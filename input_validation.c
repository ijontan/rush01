/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 00:22:41 by itan              #+#    #+#             */
/*   Updated: 2022/08/27 00:38:49 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"
#include <stdbool.h>

bool	check_correct_argc(int argc)
{
	if (argc == 1)
		return (true);
	return (false);
}

bool	check_correct_value(char *src)
{
	int i;

	while (src[i])
	{
		if (i % 2 == 1 && src[i] != 32)
			return (false);
		if (i % 2 == 0 && (src[i] > 52 || src[i] < 49))
			return (false);
		i++;
	}
	if (i == 31)
		return (true);
	return (false);
}