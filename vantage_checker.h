/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vantage_checker.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:29:53 by yraji             #+#    #+#             */
/*   Updated: 2022/08/28 17:10:55 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VANTAGE_CHECKER_H
# define VANTAGE_CHECKER_H
# include <stdbool.h>

bool	ft_vantage_checker(int **grid, int col, int row);
bool	ft_vantage_checker_left(int **grid, int row, int n);
bool	ft_vantage_checker_right(int **grid, int row, int n);
bool	ft_vantage_checker_top(int **grid, int col, int n);
bool	ft_vantage_checker_bottom(int **grid, int col, int n);

#endif