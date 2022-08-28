/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:57:04 by itan              #+#    #+#             */
/*   Updated: 2022/08/28 16:57:19 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_size.h"
#include "optimise.h"

// solving all the boxes with only one possible answer with the clues
// eg. solve_top_row would be solving the boxes with the clues on the top row
void	solve_known_ans(int **grid)
{
	int	n;

	n = get_size(grid);
	solve_top_row(grid, n);
	solve_bottom_row(grid, n);
	solve_left_col(grid, n);
	solve_right_col(grid, n);
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

void	solve_left_col(int **grid, int n)
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

void	solve_right_col(int **grid, int n)
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
