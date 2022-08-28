/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:58:39 by itan              #+#    #+#             */
/*   Updated: 2022/08/28 17:09:01 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include <stdlib.h>

int	*ft_input_parse(char *str)
{
	int	*dest;
	int	i;
	int	j;
	int	len;

	len = 0;
	while (str[len])
		len++;
	dest = (int *)malloc(sizeof(int) * (len + 1) / 2 + sizeof(int));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= 49 && str[i] <= 57)
		{
			dest[j] = str[i] - 48;
			j++;
		}
		i++;
	}
	return (dest);
}

/*
generate a grid of (N+2)*(N+2) (for now is 6) the 
extra two is for saving the clues in the grid
*src is the array containing the parsed argv[1]
*/
int	**generate_grid(int *src)
{
	int	**grid;
	int	i;
	int	j;
	int	len;

	len = 0;
	while (src[len] > 0)
		len++;
	grid = grid_malloc(len);
	i = 0;
	j = 1;
	while (i < len / 4)
		grid[0][j++] = src[i++];
	j = 1;
	while (i < len / 4 * 2)
		grid[len / 4 + 1][j++] = src[i++];
	j = 1;
	while (i < len / 4 * 3)
		grid[j++][0] = src[i++];
	j = 1;
	while (i < len)
		grid[j++][len / 4 + 1] = src[i++];
	free(src);
	return (grid);
}

int	**grid_malloc(int len)
{
	int	i;
	int	j;
	int	**grid;

	i = -1;
	grid = (int **)malloc((len / 4 + 3) * sizeof(int *));
	while (++i < len / 4 + 3)
	{
		grid[i] = (int *)malloc((len / 4 + 3) * sizeof(int));
		j = -1;
		while (++j < len / 4 + 3)
			grid[i][j] = 0;
	}
	return (grid);
}
