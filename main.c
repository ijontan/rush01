/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:37:35 by itan              #+#    #+#             */
/*   Updated: 2022/08/27 09:47:45 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c);
int		*ft_input_parse(char *src);

int	main(int argc, char const *argv[])
{
	if (!check_correct_argc(argc) || !check_correct_value(argv[1]))
		return (0);
	return (0);
}

int	*ft_input_parse(char *src)
{
	int	*dest;
	int	i;
	int	j;

	dest = (int *)malloc(16);
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] >= 49 && src[i] <= 52)
		{
			dest[j] = src[i] - 48;
			j++;
		}
		i++;
	}
	return (dest);
}

int	**generate_grid(int *src)
{
	int	**grid;
	int	i;
	int	j;

	i = 0;
	grid = (int **)malloc(6 * sizeof(int *));
	while (i < 6)
		grid[i] = (int *)malloc(6 * sizeof(int));
	i = 0;
	j = 1;
	while (i < 4)
		grid[0][j++] = src[i++];
	while (i < 8)
		grid[5][j++] = src[i++];
	while (i < 12)
		grid[j++][0] = src[i++];
	while (i < 16)
		grid[j++][5] = src[i++];
	return (grid);
}

bool	ft_is_possible(int **grid, int column, int row, int value)
{
	int	i;

	if (row == 1 && grid[row][0] + value > 5)
		return (false);
	if (column == 1 && grid[0][column] + value > 5)
		return (false);
	if (row == 4 && grid[row][5] + value > 5)
		return (false);
	if (column == 4 && grid[5][column] + value > 5)
		return (false);
	i = 0;
	while (grid[row][++i] < 5)
		if (grid[row][i] == value)
			return (false);
	i = 0;
	while (grid[++i][column] < 5)
		if (grid[i][column] == value)
			return (false);
	return (true);
}

void	ft_solve(char **grid, int column, int row)
{
	int	nb;

	nb = 0;
	while (column < 4)
	{
		while (row < 4)
		{
			if (grid[row + 1][column + 1] == 0)
			{
				while (nb < 5)
				{
					if (ft_is_possible(grid, column + 1, row + 1, nb))
					{
						grid[row + 1][column + 1] = nb;
						ft_solve(grid, column, row);
						grid[row + 1][column + 1] = 0;
					}
					nb++;
				}
				return ;
			}
			row++;
		}
		column++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}