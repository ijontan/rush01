#include <stdbool.h>

bool	ft_vantage_checker(int **grid, int col, int row, int nb)
{
	if (col == 4)
		if (!ft_vantage_checker_top(grid, col, nb))
			return (false);
	if (col == 4)
		if (!ft_vantage_checker_bottom(grid, col, nb))
			return (false);
	if (row == 4)
		if (!ft_vantage_checker_left(grid, row, nb))
			return (false);
	if (row == 4)
		if (!ft_vantage_checker_right(grid, row, nb))
			return (false);
	return (true);
}

bool	ft_vantage_checker_left(int **grid, int row, int nb)
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

bool	ft_vantage_checker_right(int **grid, int row, int nb)
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

bool	ft_vantage_checker_top(int **grid, int col, int nb)
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

bool	ft_vantage_checker_bottom(int **grid, int col, int nb)
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
