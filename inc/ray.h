/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:37:28 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/23 16:01:19 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct s_ray	t_ray;

struct	s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

#include <stdio.h>

# define PRINT_RAY(r) dprintf(2, "Ray: orig: %f %f %f, dir: %f %f %f\n", r.orig.x, r.orig.y, r.orig.z, r.dir.x, r.dir.y, r.dir.z)

t_ray		*ray_new(t_point3 *orig, t_vec3 *dir);
t_ray		ray(t_point3 *orig, t_vec3 *dir);
t_point3	*ray_at(t_ray *ray, double t);
t_ray ray_to_pixel(t_camera *c, int px, int py);
t_ray ray_init(t_render *rnd, t_camera *cam, int px, int py);

#endif /* RAY_H */
