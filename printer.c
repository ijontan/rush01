/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:57:48 by itan              #+#    #+#             */
/*   Updated: 2022/08/28 16:58:15 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
