/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:54:51 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/28 21:46:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

t_ray		ray_new(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	if (!ray)
		return (NULL);
	ray.orig = orig;
	ray.dir = dir;
	return (ray);
}

t_point3	ray_position(t_ray ray, float t)
{
	t_point3	pos;

	pos = add_tuples(ray.orig, mult_tuple(ray.dir, t));
	return (pos);
}

t_ray		ray_transform(t_ray ray, t_matrix *matrix)
{
	t_ray	new_ray;

	new_ray.orig = multiply_matrix_tuple(matrix, ray.orig);
	new_ray.dir = multiply_matrix_tuple(matrix, ray.dir);
	return (new_ray);
}
