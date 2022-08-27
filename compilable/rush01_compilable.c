#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

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

void	ft_print_grid(int **grid, int n)
{
	int	row;
	int	col;

	row = 0;
	while (++row <= n)
	{
		col = 0;
		while (++col < n)
		{
			ft_putchar(grid[row][col] + '0');
			ft_putchar(' ');
		}
		ft_putchar(grid[row][col] + '0');
		ft_putchar('\n');
	}
}
int	get_size(int **grid)
{
	int	i;

	i = 0;
	while (grid[0][i] != 0)
		i++;
	return (i - 2);
}
bool	ft_vantage_checker_left(int **grid, int row, int n)
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

bool	ft_vantage_checker_right(int **grid, int row, int n)
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

bool	ft_vantage_checker_top(int **grid, int col, int n)
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

bool	ft_vantage_checker_bottom(int **grid, int col, int n)
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
bool	ft_vantage_checker(int **grid, int row, int col)
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

void	ft_print_grid(int **grid, int n);
// check if the value is possible
// first 4 if statement is to check the edges, if value
//	+ clue next to the edge bigger than 5 it would be false
bool	ft_is_possible(int **grid, int col, int row, int value)
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

// ft_solve accepts 3 arguments, nothing more,
//	nothing less. data type must correspond to the var to be referenced
bool	ft_solve(int **grid, int n)
{
	int	nb;
	int	row;
	int	col;

	row = 0;
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			nb = 1;
			if (grid[row + 1][col + 1] == 0)
			{
				while (nb < n + 1)
				{
					if (ft_is_possible(grid, col + 1, row + 1, nb))
					{
						grid[row + 1][col + 1] = nb;
						if (ft_vantage_checker(grid, col + 1, row + 1))
							return (true);
						if (ft_solve(grid, n))
							return (true);
						grid[row + 1][col + 1] = 0;
					}
					nb++;
				}
				return (false);
			}
			col++;
		}
		row++;
	}
	return (false);
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
		// checks if the even arguments are spaces or not, only spaces allowed
		// as argument delimiters
		if (i % 2 == 1 && src[i] != 32)
			return (false);
		// checks if the odd arguments are valide character numbers, only valid
		// character numbers are allowed
		if (i % 2 == 0 && (src[i] < 49 || src[i] > 57))
			return (false);
		i++;
	}
	// checks if the total count of arguments (spaces and numbers) is not equal
	// to 32, (16(numbers) + 16(spaces) = 32)
	if ((i + 1) % 8 == 0)
		return (true);
	return (false);
}

//parses the 1 dimensional input argument,
//and fills it into a 1 dimensional array.
int	*ft_input_parse(char *str)
{
	int	*dest;
	int	i;
	int	j;
	int	len;

	len = 0;
	while (str[len])
		len++;
	// allocate memory for the argument array
	dest = (int *)malloc(sizeof(int) * (len + 1) / 2 + sizeof(int));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= 49 && str[i] <= 57)
		{
			// if the value is within 1 ~ 4, convert char back to int
			dest[j] = str[i] - 48;
			j++;
		}
		i++;
	}
	return (dest);
}

// generate a grid of (N+2)*(N+2) (for now is 6) the extra two is for saving the clues in the grid
// *src is the array containing the parsed argv[1]
int	**generate_grid(int *src)
{
	int	**grid;
	int	i;
	int	j;
	int	len;

	len = 0;
	while (src[len] > 0)
		len++;
	// i to iterate horizontally through *src (AKA clues)
	// j to move array to next index (inside 2d grid)
	i = -1;
	// create a int array with 6 slots of size integer
	grid = (int **)malloc((len / 4 + 3) * sizeof(int *));
	// for each previously created slot,
	//make another int array with 6 slots of size integer inside
	while (++i < len / 4 + 3)
	{
		grid[i] = (int *)malloc((len / 4 + 3) * sizeof(int));
		j = -1;
		while (++j < len / 4 + 3)
			grid[i][j] = 0;
	}
	grid[0][0] = 1;
	grid[0][len / 4 + 1] = 1;
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
	return (grid);
}

void	solve_top_row(int **grid, int n)
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

void	solve_bottom_row(int **grid, int n)
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

void	solve_left_row(int **grid, int n)
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

void	solve_right_row(int **grid, int n)
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
void	solve_known_ans(int **grid)
{
	int	n;

	n = get_size(grid);
	solve_top_row(grid, n);
	solve_bottom_row(grid, n);
	solve_left_row(grid, n);
	solve_right_row(grid, n);
}

void	ft_errormsg(void)
{
	ft_putstr("ERROR\n");
}

int	main(int argc, char *argv[])
{
	int **grid;
	int n;
	int i;
	// check if input format is correct
	if (!check_correct_argc(argc) || !check_correct_value(argv[1]))
		return (0);

	// generate the grid
	grid = generate_grid(ft_input_parse(argv[1]));
	//get size of grid
	n = get_size(grid);
	// ft_print_grid(grid);

	// solve for spots that are definite first (optimization)
	solve_known_ans(grid);
	// brute forcing
	ft_solve(grid, n);

	// check if the combination is possible

	//printing
	ft_print_grid(grid, n);

	//free memory
	i = -1;
	while (++i < n + 2)
		free(grid[i]);

	free(grid);

	return (0);
}