#include "vantage_checker.h"
#include <stdbool.h>

bool	ft_vantage_checker(int **grid, int row, int col)
{
	if (!(row == 4 && col == 4))
		return (false);
	col = 0;
	while (++col < 4 + 1)
	{
		if (!ft_vantage_checker_top(grid, col))
			return (false);
		if (!ft_vantage_checker_bottom(grid, col))
			return (false);
	}
	row = 0;
	while (++col < 4 + 1)
	{
		if (!ft_vantage_checker_left(grid, row))
			return (false);
		if (!ft_vantage_checker_right(grid, row))
			return (false);
	}
	return (true);
}

bool	ft_vantage_checker_left(int **grid, int row)
{
	int	num_building;
	int	i;
	int	current_high;

	num_building = 0;
	current_high = 0;
	i = -1;
	while (++i < 4)
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

bool	ft_vantage_checker_right(int **grid, int row)
{
	int	num_building;
	int	i;
	int	current_high;

	num_building = 0;
	current_high = 0;
	i = 4;
	while (--i >= 0)
	{
		if (grid[row][i + 1] > current_high)
		{
			num_building++;
			current_high = grid[row][i + 1];
		}
	}
	if (grid[row][5] != num_building)
		return (false);
	return (true);
}

bool	ft_vantage_checker_top(int **grid, int col)
{
	int	num_building;
	int	i;
	int	current_high;

	num_building = 0;
	current_high = 0;
	i = -1;
	while (++i < 4)
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

bool	ft_vantage_checker_bottom(int **grid, int col)
{
	int	num_building;
	int	i;
	int	current_high;

	num_building = 0;
	current_high = 0;
	i = 4;
	while (--i >= 0)
	{
		if (grid[i + 1][col] > current_high)
		{
			num_building++;
			current_high = grid[i + 1][col];
		}
	}
	if (grid[5][col] != num_building)
		return (false);
	return (true);
}
