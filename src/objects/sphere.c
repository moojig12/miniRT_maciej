/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:12:37 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/27 14:04:52 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/objects.h"

t_sphere	sphere(t_point3 c, float r)
{
	t_sphere	s;

	s.center = c;
	s.radius = r;
	return (s);
}

/*
 * equation of a sphere with cneter at point C
 * and ray P:
 * `(C - P)*(C - P) = r^2` // TODO: find out why there is two (C-P)
 * this equation could be simplified to a quadratic version:
 * `t^2 * d * d − 2td * (C − Q) + (C − Q) + (C − Q) − r^2 = 0`
 * where:
 * a = d * d
 * b = -2d * (C - Q)
 * c = (C - Q) * (C - Q) - r^2
 * from this we can get a discriminant:
 * D = (-b +- sqrt(b^2 - 4ac)) / (2a)
 */
bool	hit_sphere(const t_sphere *s, t_ray *r)
{
	float		a;
	float		b;
	float		c;
	float		d;

	a = dot(&r->dir, &r->dir);
	v_vec3_mult(&r->dir, -2.0f);
	v_vec3_sub((t_vec3 *) &s->center, &r->orig);
	// b = -2 * dot(&r->orig, &r->dir);
	b = dot(&r->dir, (t_vec3 *) &s->center);
	c = dot((t_vec3 *) &s->center, (t_vec3 *) &s->center) - (s->radius * s->radius);
	d = (b * b) - 4.0f * a * c;
	return (d >= 0.0f);
}
