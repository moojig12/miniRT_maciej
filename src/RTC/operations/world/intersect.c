/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:36:41 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/28 22:59:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static t_x sort_intersections(t_x xs);

//intersect world
t_x	intersect_world(t_world *world, t_ray ray)
{
	t_x xs;
	t_x xs_temp;
	t_shape *shape_temp;
	
	shape_temp = world->shapes;
	xs.count = 0;
	xs = intersect(world->shapes, ray);
	world->shapes = world->shapes->next;
	while (world->shapes)
	{
		xs_temp = intersect(world->shapes, ray);
		if (xs_temp.count == 0)
		{
			if (xs.count == 0)
				xs = xs_temp;
			else
				xs = intersections((xs.count + xs_temp.count), xs, xs_temp);
		}
		world->shapes = world->shapes->next;
	}
	world->shapes = shape_temp;
	xs = sort_intersections(xs);
	return (xs);
}

t_x sort_intersections(t_x xs)
{
	int i;
	int j;
	t_i temp;

	i = 0;
	while (i < xs.count)
	{
		j = i + 1;
		while (j < xs.count)
		{
			if (xs.i[i].t > xs.i[j].t)
			{
				temp = xs.i[i];
				xs.i[i] = xs.i[j];
				xs.i[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (xs);
}
