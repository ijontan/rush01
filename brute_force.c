#include "brute_force.h"
#include <stdbool.h>

// check if the value is possible
// first 4 if statement is to check the edges, if value + clue next to the edge bigger than 5 it would be false 
bool ft_is_possible(int **grid,	int col, int row, int value)
{
	int	i;

	if ((row == 1) && (grid[row][0] + value > 5))
		return (false);
	if ((col == 1) && (grid[0][col] + value > 5))
		return (false);
	if ((row == 4) && (grid[row][5] + value > 5))
		return (false);
	if ((col == 4) && (grid[5][col] + value > 5))
		return (false);
	i = 0;
	while (grid[row][++i] < 5)
		if (grid[row][i] == value)
			return (false);
	i = 0;
	while (grid[++i][col] < 5)
		if (grid[i][col] == value)
			return (false);
	return (true);
}

// ft_solve accepts 3 arguments, nothing more, nothing less. data type must correspond to the var to be referenced
void	ft_solve(int **grid, int col, int row)
{
	int	nb;

	nb = 0;
	while (col < 4)
	{
		while (row < 4)
		{
			if (grid[row + 1][col + 1] == 0)
			{
				while (nb < 5)
				{
					if (ft_is_possible(grid, col + 1, row + 1, nb))
					{
						grid[row + 1][col + 1] = nb;
						ft_solve(grid, col, row);
						grid[row + 1][col + 1] = 0;
					}
					nb++;
				}
				return ;
			}
			row++;
		}
		col++;
	}
}
