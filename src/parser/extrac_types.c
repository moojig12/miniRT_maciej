/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrac_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:53:38 by astavrop          #+#    #+#             */
/*   Updated: 2024/11/17 17:17:01 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../inc/types.h"
#include <stdio.h>
#include <string.h>

float	ft_atof(char *line, size_t start)
{
	size_t	i;
	int		sign;
	double	val;
	double	pow;

	i = start;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	sign = 1;
	if ((line[i] == '+' || line[i] == '-') && i++)
	{
		if (line[i - 1] == '-')
			sign = -1;
	}
	val = 0.0;
	while (line[i] >= '0' && line[i] <= '9')
		val = val * 10.0 + (line[i++] - '0');
	pow = 1.0;
	if (line[i] == '.' && i++)
	{
		while (line[i] >= '0' && line[i] <= '9')
		{
			val = val * 10.0 + (line[i++] - '0');
			pow *= 10.0;
		}
	}
	return (sign * val/pow);
}

t_vec3	ft_atovec3(char *line, size_t start)
{
	
}
