
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

bool	ft_vantage_checker(int grid[][11], int col, int row);
bool	ft_vantage_checker_left(int grid[][11], int row, int n);
bool	ft_vantage_checker_right(int grid[][11], int row, int n);
bool	ft_vantage_checker_top(int grid[][11], int col, int n);
bool	ft_vantage_checker_bottom(int grid[][11], int col, int n);
void	ft_input_parse(char *str, int dest[36]);
void	generate_grid(int src[36], int grid[][11]);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_print_grid(int grid[][11], int n);
bool	check_correct_argc(int argc);
bool	check_correct_value(char *src);
int		get_size(int grid[][11]);
bool	ft_is_possible(int grid[][11], int col, int row, int value);
bool	ft_solve(int grid[][11], int n);

int	get_size(int grid[][11])
{
	int	i;

	i = 1;
	while (grid[0][i] != 0)
		i++;
	return (i - 1);
}
/*
this function checks if the number of arguments are not one
e.g, running the program with more, or less than 1 arguments 
is not allowed.
*/
bool	check_correct_argc(int argc)
{
	if (argc == 2)
		return (true);
	return (false);
}

/*
this function checks the pattern of the arguments passed into the program.
the inputs must all be numbers and separated by space (and only space)
this doesn't work with anything else.
this function also checks the total length of the arguments passed.
*/
bool	check_correct_value(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		// checks if the odd index are spaces or not, only spaces allowed
		// as argument delimiters
		if (i % 2 == 1 && src[i] != 32)
			return (false);
		// checks if the even index are valid character numbers, only valid
		// character numbers are allowed
		if (i % 2 == 0 && (src[i] < 49 || src[i] > 57))
			return (false);
		i++;
	}
	// checks if the total count of arguments (spaces and numbers) is divisible by 8,
	// reject user input if not divisible by 8
	if ((i + 1) % 8 == 0)
		return (true);
	return (false);
}

//parses the 1 dimensional input argument,
// and fills it into a 1 dimensional array.
void	ft_input_parse(char *str, int dest[36])
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (++i < 36)
		dest[i] = 0;
	len = 0;
	while (str[len])
		len++;
	// allocate memory for the argument array
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= 49 && str[i] <= 57)
		{
			// if the value is within 1 ~ 9, convert char back to int
			dest[j] = str[i] - 48;
			j++;
		}
		i++;
	}
}

void	solve_top_row(int grid[][11], int n)
{
	int	col;
	int	row;

	col = 0;
	while (++col <= n)
	{
		if (grid[0][col] == n)
		{
			row = 0;
			while (++row <= n)
				grid[row][col] = row;
		}
		if (grid[0][col] == 1)
			grid[1][col] = n;
		if (grid[0][col] + grid[n + 1][col] == n + 1)
			grid[grid[0][col]][col] = n;
	}
}

void	solve_bottom_row(int grid[][11], int n)
{
	int	col;
	int	row;

	col = 0;
	while (++col <= n)
	{
		if (grid[n + 1][col] == n)
		{
			row = n + 1;
			while (--row <= n)
				grid[row][col] = row;
		}
		if (grid[n + 1][col] == 1)
			grid[n][col] = n;
	}
}

void	solve_left_col(int grid[][11], int n)
{
	int	col;
	int	row;

	row = 0;
	while (++row <= n)
	{
		if (grid[row][0] == n)
		{
			col = 0;
			while (--col <= n)
				grid[row][col] = col;
		}
		if (grid[row][0] == 1)
			grid[row][1] = n;
		if (grid[row][0] + grid[row][n + 1] == n + 1)
			grid[row][grid[row][0]] = n;
	}
}

void	solve_right_col(int grid[][11], int n)
{
	int	col;
	int	row;

	row = 0;
	while (++row <= n)
	{
		if (grid[row][n + 1] == n)
		{
			col = n + 1;
			while (--col <= n)
				grid[row][col] = col;
		}
		if (grid[row][n + 1] == 1)
			grid[row][n] = n;
	}
}
void	solve_known_ans(int grid[][11])
{
	int	n;

	n = get_size(grid);
	solve_top_row(grid, n);
	solve_bottom_row(grid, n);
	solve_left_col(grid, n);
	solve_right_col(grid, n);
}

// generate a grid of (N+2)*(N+2) (for now is 6) the extra two is for saving the clues in the grid
// *src is the array containing the parsed argv[1]
void	generate_grid(int src[36], int grid[][11])
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (src[len] > 0)
		len++;
	// i to iterate horizontally through *src (AKA clues)
	// j to move array to next index (inside 2d grid)
	i = -1;
	while (++i < len / 4 + 2)
	{
		j = -1;
		while (++j < len / 4 + 2)
			grid[i][j] = 0;
	}
	// create a int array with 6 slots of size integer
	i = 0;
	j = 1;
	while (i < len / 4)
		// access first row, second col then assign clue to the slot
		grid[0][j++] = src[i++];
	j = 1;
	while (i < len / 4 * 2)
		// access last row, second col
		grid[len / 4 + 1][j++] = src[i++];
	j = 1;
	while (i < len / 4 * 3)
		// access first col, second row
		grid[j++][0] = src[i++];
	j = 1;
	while (i < len)
		// access last col, second row
		grid[j++][len / 4 + 1] = src[i++];
}

bool	ft_check_and_set(int grid[][11], int col, int row, int nb);

// check if the value is possible
// first 4 if statement is to check the edges, if value
// + clue next to the edge bigger than 5 it would be false
bool	ft_is_possible(int grid[][11], int col, int row, int value)
{
	int	i;
	int	n;

	n = get_size(grid);
	if ((col == 1) && (grid[row][0] + value > n + 1))
		return (false);
	if ((row == 1) && (grid[0][col] + value > n + 1))
		return (false);
	if ((col == n) && (grid[row][n + 1] + value > n + 1))
		return (false);
	if ((row == n) && (grid[n + 1][col] + value > n + 1))
		return (false);
	i = 0;
	while (++i < n + 1)
		if (grid[row][i] == value && i != col)
			return (false);
	i = 0;
	while (++i < n + 1)
		if (grid[i][col] == value && (i != row))
			return (false);
	return (true);
}

// ft_solve accepts 3 arguments, nothing more
//nothing less. data type must correspond to the var to be referenced

bool	ft_solve(int grid[][11], int n)
{
	int	nb;
	int	col;
	int	row;

	row = -1;
	while (++row < n)
	{
		col = -1;
		while (++col < n)
		{
			if (grid[row + 1][col + 1] == 0)
			{
				nb = 0;
				while (++nb < 5)
					if (ft_check_and_set(grid, col, row, nb))
						return (true);
				return (false);
			}
		}
	}
	return (false);
}

bool	ft_check_and_set(int grid[][11], int col, int row, int nb)
{
	int	n;

	n = get_size(grid);
	if (ft_is_possible(grid, col + 1, row + 1, nb))
	{
		grid[row + 1][col + 1] = nb;
		if (ft_vantage_checker(grid, col + 1, row + 1))
			return (true);
		if (ft_solve(grid, n))
			return (true);
		grid[row + 1][col + 1] = 0;
	}
	return (false);
}

bool	ft_vantage_checker(int grid[][11], int row, int col)
{
	int	n;

	n = get_size(grid);
	if (!(row == n && col == n))
		return (false);
	col = 0;
	while (++col < n + 1)
	{
		if (!ft_vantage_checker_top(grid, col, n))
			return (false);
		if (!ft_vantage_checker_bottom(grid, col, n))
			return (false);
	}
	row = 0;
	while (++col < n + 1)
	{
		if (!ft_vantage_checker_left(grid, row, n))
			return (false);
		if (!ft_vantage_checker_right(grid, row, n))
			return (false);
	}
	return (true);
}

bool	ft_vantage_checker_left(int grid[][11], int row, int n)
{
	int	num_building;
	int	i;
	int	current_high;

	num_building = 0;
	current_high = 0;
	i = -1;
	while (++i < n)
	{
		if (grid[row][i + 1] > current_high)
		{
			num_building++;
			current_high = grid[row][i + 1];
		}
	}
	if (grid[row][0] != num_building)
		return (false);
	return (true);
}

bool	ft_vantage_checker_right(int grid[][11], int row, int n)
{
	int	num_building;
	int	i;
	int	current_high;

	num_building = 0;
	current_high = 0;
	i = n;
	while (--i >= 0)
	{
		if (grid[row][i + 1] > current_high)
		{
			num_building++;
			current_high = grid[row][i + 1];
		}
	}
	if (grid[row][n + 1] != num_building)
		return (false);
	return (true);
}

bool	ft_vantage_checker_top(int grid[][11], int col, int n)
{
	int	num_building;
	int	i;
	int	current_high;

	num_building = 0;
	current_high = 0;
	i = -1;
	while (++i < n)
	{
		if (grid[i + 1][col] > current_high)
		{
			num_building++;
			current_high = grid[i + 1][col];
		}
	}
	if (grid[0][col] != num_building)
		return (false);
	return (true);
}

bool	ft_vantage_checker_bottom(int grid[][11], int col, int n)
{
	int	num_building;
	int	i;
	int	current_high;

	num_building = 0;
	current_high = 0;
	i = n;
	while (--i >= 0)
	{
		if (grid[i + 1][col] > current_high)
		{
			num_building++;
			current_high = grid[i + 1][col];
		}
	}
	if (grid[n + 1][col] != num_building)
		return (false);
	return (true);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_print_grid(int grid[][11], int n)
{
	int	row;
	int	col;

	row = -1;
	while (++row <= n + 1)
	{
		col = -1;
		while (++col < n + 1)
		{
			ft_putchar(grid[row][col] + 48);
			ft_putchar(' ');
		}
		ft_putchar(grid[row][col] + 48);
		ft_putchar('\n');
	}
}

int	main(int argc, char *argv[])
{
	int grid[11][11];
	int dest[36];
	int n;
	// check if input format is correct
	if (!check_correct_argc(argc) || !check_correct_value(argv[1]))
		return (0);
	ft_input_parse(argv[1], dest);

	// generate the grid
	generate_grid(dest, grid);

	// get size of grid
	n = get_size(grid);
	// solve for spots that are definite first (optimization)
	solve_known_ans(grid);

	// brute forcing
	ft_solve(grid, n);

	// check if the combination is possible

	//printing
	ft_print_grid(grid, n);

	//free memory

	return (0);
}