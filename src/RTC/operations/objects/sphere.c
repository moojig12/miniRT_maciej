/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:17:22 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/12 15:22:23 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

// Create a new sphere object
t_sphere	*sphere_new()
{
	t_sphere	*sphere;
	static int	id = 0;

	sphere = malloc(sizeof(t_sphere));
	sphere->id = id++;
	sphere->coords = new_point3(0, 0, 0);
	sphere->radius = 1;
	sphere->color = new_tuple(0, 0, 0, 0);
	sphere->transform = *init_identity_matrix(4);
	sphere->material = default_material();
	return (sphere);
}
