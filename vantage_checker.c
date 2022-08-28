/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vantage_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:10:22 by itan              #+#    #+#             */
/*   Updated: 2022/08/28 17:10:34 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_size.h"
#include "vantage_checker.h"
#include <stdbool.h>

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
