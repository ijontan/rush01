#include <get_size.h>

void	solve_known_ans(int **grid)
{
	int	n;

	n = get_size(grid);
	solve_top_row(grid, n);
	solve_bottom_row(grid, n);
	solve_left_row(grid, n);
	solve_right_row(grid, n);
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
