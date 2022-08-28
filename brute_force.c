#include "brute_force.h"
#include "get_size.h"
#include "vantage_checker.h"
#include <stdbool.h>

bool	ft_check_and_set(int **grid, int col, int row, int nb);

// check if the value is possible
// first 4 if statement is to check the edges, if value
// + clue next to the edge bigger than 5 it would be false
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

// ft_solve accepts 3 arguments, nothing more
//nothing less. data type must correspond to the var to be referenced

bool	ft_solve(int **grid, int n)
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

bool	ft_check_and_set(int **grid, int col, int row, int nb)
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
