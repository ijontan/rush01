/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:48:05 by itan              #+#    #+#             */
/*   Updated: 2022/08/28 16:55:43 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"
#include <stdbool.h>

/*
this function checks if the number of arguments are not one
e.g, running the program with more, or less than 1 arguments 
is not allowed.
*/
bool	check_correct_argc(int argc)
{
	if (argc == 2)
		return (true);
	return (false);
}

/*
this function checks the pattern of the arguments passed into the program.
the inputs must all be numbers and separated by space (and only space)
this doesn't work with anything else.
this function also checks the total length of the arguments passed.
*/
bool	check_correct_value(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (i % 2 == 1 && src[i] != 32)
			return (false);
		if (i % 2 == 0 && (src[i] < 49 || src[i] > 57))
			return (false);
		i++;
	}
	if ((i + 1) % 8 == 0)
		return (true);
	return (false);
}
