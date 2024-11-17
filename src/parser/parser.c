/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:02:21 by astavrop          #+#    #+#             */
/*   Updated: 2024/11/17 16:04:31 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../inc/parser.h"

int	parse_scene(char *filename)
{
	if (!is_valid_filename(filename) || !has_valid_perms(filename))
	{
		ft_dprintf(2, "Error: scene could not be parsed.\n");
		return (-1);
	}
}
