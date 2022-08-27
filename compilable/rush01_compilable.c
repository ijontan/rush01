#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4
void	ft_print_grid(int **grid);
// check if the value is possible
// first 4 if statement is to check the edges, if value + clue next to the edge bigger than 5 it would be false 
bool ft_is_possible(int **grid,	int col, int row, int value)
{
	int	i;

	if ((col == 1) && (grid[row][0] + value > 5))
		return (false);
	if ((row == 1) && (grid[0][col] + value > 5))
		return (false);
	if ((col == 4) && (grid[row][5] + value > 5))
		return (false);
	if ((row == 4) && (grid[5][col] + value > 5))
		return (false);
	i = 0;
	while (++i< 5)
		if (grid[row][i] == value && i != col)
			return (false);
	i = 0;
	while (++i < 5)
		if (grid[i][col] == value && (i != row))
			return (false);
	return (true);
}

// ft_solve accepts 3 arguments, nothing more, nothing less. data type must correspond to the var to be referenced
void	ft_solve(int **grid)
{
	int	nb;
int row=0;

	
	while (row < 4)
	{
		int col=0;
		while (col < 4)
		{	
			nb = 1;
			if (grid[row + 1][col + 1] == 0)
			{
				while (nb < 5)
				{
					if (ft_is_possible(grid, col + 1, row + 1, nb))
					{
						grid[row + 1][col + 1] = nb;
						ft_solve(grid );
						grid[row + 1][col + 1] = 0;
						
					}

					nb++;
				}
				
				return;
			}
			col++;
		}
		row++;
	}
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
	int	i = 0;

	while (src[i])
	{
		// checks if the even arguments are spaces or not, only spaces allowed
		// as argument delimiters
		if (i % 2 == 1 && src[i] != 32)
			return (false);
		// checks if the odd arguments are valide character numbers, only valid 
		// character numbers are allowed
		if (i % 2 == 0 && (src[i] < 49 || src[i] > 52))
			return (false);
		i++;
	}
	// checks if the total count of arguments (spaces and numbers) is not equal
	// to 32, (16(numbers) + 16(spaces) = 32)
	if (i == 31)
		return (true);
	return (false);
}

//parses the 1 dimensional input argument, and fills it into a 1 dimensional array. 
int	*ft_input_parse(char *str)
{
	int	*dest;
	int	i;
	int	j;

	// allocate memory for the argument array
	dest = (int *)malloc(sizeof(int) * 16);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= 49 && str[i] <= 52)
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
	// i to iterate horizontally through *src (AKA clues)
	int	i;
	// j to move array to next index (inside 2d grid)
	int	j;

	i = -1;
	// create a int array with 6 slots of size integer
	grid = (int **)malloc(6 *sizeof(int *));
	// for each previously created slot, make another int array with 6 slots of size integer inside
	while (++i < 6)
	{
		grid[i] = (int *)malloc(6 * sizeof(int));
		j = 0;
		while (j < 6)
		{
			grid[i][j] = 0;
			j++;
		}
	}



	
	i = 0;
	j = 1;
	while (i < 4)
		// access first row, second col then assign clue to the slot
		grid[0][j++] = src[i++];
	j = 1;
	while (i < 8)
		// access last row, second col
		grid[5][j++] = src[i++];
	j = 1;
	while (i < 12)
		// access first col, second row
		grid[j++][0] = src[i++];
	j = 1;
	while (i < 16)
		// access last col, second row
		grid[j++][5] = src[i++];
	return (grid);
}

void solve_known_ans(int **grid)
{
    int i;
    int j;
    i= 0;
    while (i <= N)
    {
        if (grid[0][i] == 4)
        {
            j = 0;
            while (++j <= N)
            {
                grid[j][i] = j;
            }
        }
    }
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_print_grid(int **grid)
{
	int row = 0;

	while (++row <= N)
	{
		int col = 0;
		while (++col < N)
		{
			ft_putchar(grid[row][col] + '0');
			ft_putchar(' ');
		}

			ft_putchar(grid[row][col] + '0');
	
		ft_putchar('\n');
	}
}

void	ft_errormsg(void)
{
	ft_putstr("ERROR\n");
}

int	main(int argc, char *argv[])
{
	int **grid;
	// check if input format is correct
	if (!check_correct_argc(argc) || !check_correct_value(argv[1]))
		return (0);

	// generate the grid
	grid = generate_grid(ft_input_parse(argv[1]));

	// ft_print_grid(grid);
	ft_print_grid(grid);

	// solve for spots that are definite first (optimization)

	// brute forcing
	ft_solve(grid);
	
	// check if the combination is possible

	//printing
	ft_print_grid(grid);

	//free memory
	free(grid);

	return (0);
}