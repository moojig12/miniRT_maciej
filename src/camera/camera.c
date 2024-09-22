/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:06:27 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/22 17:27:24 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mrt.h"

static int	viewport_init(t_camera *c);

t_camera	camera_new(t_render *render)
{
	t_camera	c;

	c = *render->options->objects.camera;
	c.aspect_ratio = (double) render->vp_img->width / render->vp_img->height;
	c.img_width = render->vp_img->width;
	c.img_height = render->vp_img->height;
	c.max_depth = MAX_DEPTH;
	viewport_init(&c);
	c.focal_dist = 1.0f;
	c.horiz = vec3(c.vp_width, 0.0f, 0.0f);
	c.vert = vec3(0.0f, c.vp_height, 0.0f);
	c.llc = vec3(-c.vp_width / 2, -c.vp_height / 2, -c.focal_dist);
	return(c);
}

static int	viewport_init(t_camera *c)
{
	c->vp_height = 2 * tan(deg_to_rad(c->FOV) / 2);
	c->vp_width = c->vp_height * c->aspect_ratio;
	c->pix_size = c->vp_width / c->img_width;
	return (0);
}

#define U 0
#define V 1
#define HORIZONTAL 0
#define VERTICAL 1

t_ray ray_init(t_render *rnd, t_camera *cam, int px, int py)
{
	double	uv[2];
	t_vec3	dir;
	t_vec3	axis[2];
	t_ray	r;

	axis[0] = cam->horiz;
	axis[1] = cam->vert;
	uv[U] = (float) px / (rnd->window->width - 1);
	uv[V] = (float) py / (rnd->window->height - 1);
	dir = cam->llc;
	v_vec3_mult(&axis[HORIZONTAL], uv[U]);
	v_vec3_mult(&axis[VERTICAL], uv[V]);
	v_vec3_add(&dir, &axis[HORIZONTAL]);
	v_vec3_add(&dir, &axis[VERTICAL]);
	v_vec3_sub(&dir, &cam->center);
	v_vec3_unit(&dir);
	r = ray(&cam->center, &dir);
	return (r);
}

#define OFFSET_X 0
#define OFFSET_Y 1
#define WORLD_X 2
#define WORLD_Y 3

t_ray ray_to_pixel(t_camera *c, int px, int py)
{
	t_ray	ray;
	double	x_offset;
	double	y_offset;
	double	world_x;
	double	world_y;

	x_offset = (px + 0.5) * c->pix_size;
	y_offset = (py + 0.5) * c->pix_size;
	world_x = c->vp_width / 2 - x_offset;
	world_y = c->vp_height / 2 - y_offset;
	ray.orig = c->center;
	ray.dir = point3(world_x, world_y, 1);
	v_vec3_neg(&ray.dir);
	v_vec3_unit(&ray.dir);
	return (ray);
}
