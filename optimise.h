/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:57:30 by itan              #+#    #+#             */
/*   Updated: 2022/08/28 16:57:31 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMISE_H
# define OPTIMISE_H

void	solve_known_ans(int **grid);
void	solve_top_row(int **grid, int n);
void	solve_bottom_row(int **grid, int n);
void	solve_left_col(int **grid, int n);
void	solve_right_col(int **grid, int n);

#endif