/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:59:34 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/27 21:08:52 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/color.h"
#include "../../lib/libft/libft.h"
#include "../../inc/objects.h"
#include <stdio.h>

int	write_color(int fd, t_color *pixel_color)
{
	int	r;
	int	g;
	int	b;

	r = (pixel_color->a[R] * 255.999);
	g = (pixel_color->a[G] * 255.999);
	b = (pixel_color->a[B] * 255.999);
//	ft_putnbr_fd(r, fd);
//	ft_putstr_fd(" ", fd);
//	ft_putnbr_fd(g, fd);
//	ft_putstr_fd(" ", fd);
//	ft_putnbr_fd(b, fd);
//	ft_putstr_fd("\n", fd);
	dprintf(fd, "%d %d %d\n", r, g, b);
	return (0);
}

t_color	color(float red, float green, float blue)
{
	t_color	c;

	c.a[R] = red;
	c.a[G] = green;
	c.a[B] = blue;
	return (c);
}

t_color	ray_color(t_ray *r)
{
	/* TEST */
	t_point3	sc1 = point3(4, 4, -40); // Test sphere center
	t_sphere	s1 = sphere(sc1, 4.0f);
	t_point3	sc2 = point3(-1, -1, -5); // Test sphere center
	t_sphere	s2 = sphere(sc2, 0.5f);
	t_point3	p1c = point3(0, 0, -1);
	t_vec3		p1n = vec3(-0.5f, -2, 0.1f);
	t_plane		p1 = plane(p1c, p1n);
	if (hit_sphere(&s1, r))
		return (color(1, 0, 0));
	else if (hit_sphere(&s2, r))
		return (color(0, 1, 0));
	else if (hit_plane(&p1, r))
		return (color(0.3f, 0.3f, 0.3f));

	t_color	clr1;
	t_color	clr2;

	t_vec3	udir = *vec3_unit(&r->dir);
	float	a = 0.5f * (udir.a[Y] + 1.0f);
	clr1 = color(1, 1, 1);
	clr2 = color(0.5f, 0.7f, 1);
	v_vec3_mult(&clr1, 1.0f - a);
	v_vec3_mult(&clr2, a);
	v_vec3_add(&clr1, &clr2);
	return (clr1);
}