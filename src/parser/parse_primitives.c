/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_primitives.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:47:54 by astavrop          #+#    #+#             */
/*   Updated: 2024/11/17 16:53:17 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"
#include "../../inc/types.h"

t_sphere	*parse_sp(char *line)
{
	static int	id = 0;
	t_sphere	*sp;

	sp = gc_malloc(sizeof(*sp));
	if (!sp)
		return (NULL);
	sp->id = id++;
	sp->coords = new_point3(0, 0, 0);
	sp->radius = 1;
	sp->color = new_tuple(0, 0, 0, 0);
	sp->transform = *init_identity_matrix(4);
	sp->material = default_material();
}
