/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sphere.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: astavrop <astavrop@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/26 15:12:37 by astavrop		  #+#	#+#			 */
/*   Updated: 2024/09/23 17:51:10 by astavrop		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "mrt.h"

t_sphere	sphere(t_point3 c, float r)
{
	t_sphere	s;

	s.coords = c;
	s.radius = r;
	return (s);
}

#define SE_A 0
#define SE_B 1
#define SE_C 2

/*
 * equation of a sphere with cneter at point C
 * and ray P:
 * `(C - P)*(C - P) = r^2`
 * this equation could be simplified to a quadratic version:
 * `t^2 * d * d − 2td * (C − Q) + (C − Q) + (C − Q) − r^2 = 0`
 * where:
 * a = d * d
 * b = -2d * (C - Q)
 * c = (C - Q) * (C - Q) - r^2
 * from this we can get a discriminant:
 * D = (-b +- sqrt(b^2 - 4ac)) / (2a)
 */
bool	hit_sphere(t_sphere *s, t_ray *r)
{
	double	sec[3];
	double discriminant;
	t_vec3 oc;

	oc = vec3(r->orig.x, r->orig.y, r->orig.z);
	v_vec3_sub(&oc, &s->coords);
	sec[SE_A] = dot(&r->dir, &r->dir);
	sec[SE_B] = 2 * dot(&r->dir, &oc);
	sec[SE_C] = dot(&oc, &oc) - (s->radius * s->radius);
	discriminant = (sec[SE_B] * sec[SE_B]) - 4.0f * sec[SE_A] * sec[SE_C];
	return (discriminant >= 0);
	// if (discriminant >= 0)
	// {
		// discriminant = sqrt(discriminant);
		// *t = (-sec[SE_B] - discriminant) / (2.0f * sec[SE_A]);
		// if (*t < 0)
		// {
			// *t = (-sec[SE_B] + discriminant) / (2.0f * sec[SE_A]);
		// }
		// return (*t >= 0);
	// }
	// return false;
}
