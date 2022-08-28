/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:36:09 by itan              #+#    #+#             */
/*   Updated: 2022/08/28 16:56:17 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_VALIDATION_H
# define INPUT_VALIDATION_H
# include <stdbool.h>

bool	check_correct_argc(int argc);
bool	check_correct_value(char *src);

#endif