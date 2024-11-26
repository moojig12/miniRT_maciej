/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:17:22 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/26 18:02:02 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_shape	*sphere_new(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = SPHERE;
	shape->transform = *init_identity_matrix(4);
	shape->material = *default_material();
	shape->next = NULL;
	return (shape);
}

t_shape *plane_new(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	shape->type = PLANE;
	shape->transform = *init_identity_matrix(4);
	shape->material = *default_material();
	shape->next = NULL;
	return (shape);
}