/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:44:46 by itan              #+#    #+#             */
/*   Updated: 2022/08/28 16:45:48 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRUTE_FORCE_H
# define BRUTE_FORCE_H
# include <stdbool.h>

bool	ft_is_possible(int **grid, int col, int row, int value);
bool	ft_solve(int **grid, int n);

#endif