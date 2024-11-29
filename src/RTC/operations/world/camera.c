/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:52:58 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/29 09:59:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

static void	get_pixel_size(t_camera *camera);

t_camera	*camera_new(int hsize, int vsize, float fov)
{
	t_camera *camera;

	camera = malloc(sizeof(t_camera));
	camera->hsize = hsize;
	camera->vsize = vsize;
	camera->fov = fov;
	camera->transform = init_identity_matrix(4);
	get_pixel_size(camera);
	return(camera);
}

static void	get_pixel_size(t_camera *camera)
{
	float	half_view;
	float	aspect;

	half_view = tan(camera->fov/2);
	aspect = (float)camera->hsize / (float)camera->vsize;
	if(aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / camera->hsize;
}

t_ray ray_for_pixel(t_camera *camera, int px, int py)
{
	float	xoffset;
	float	yoffset;
	float	world_x;
	float	world_y;
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;
	t_ray	ray;

	xoffset = (px + 0.5) * camera->pixel_size;
	yoffset = (py + 0.5) * camera->pixel_size;
	
	world_x = camera->half_width - xoffset;
	world_y = camera->half_height - yoffset;

	pixel = multiply_matrix_tuple(inverse(camera->transform), new_point3_p(world_x, world_y, -1));
	origin = multiply_matrix_tuple(inverse(camera->transform), new_point3_p(0, 0, 0));
	direction = normalize(sub_tuple(pixel, origin));

	ray.dir = direction;
	ray.orig = origin;
	return(ray);
}

mlx_image_t *render(t_camera *camera, t_world *world, mlx_image_t *image, mlx_t *mlx)
{
	t_ray ray;
	t_color3 color;
	int color_int;
	int y = 0;
	int x = 0;
	int total = camera->hsize * camera->vsize;

	while(y < camera->vsize)
	{
		x = 0;
		while(x < camera->hsize)
		{
			printf("Rendering %d/%d\n", y * camera->hsize + x, total);
			ray = ray_for_pixel(camera, x, y);			
			color = color_at(world, ray, RECURSIVE_DEPTH);
			// printf("%f %f %f\n", color.r, color.g, color.b);
			color_int = color_to_int(color);
			mlx_put_pixel(image, x, y, color_int);
			mlx_image_to_window(mlx, image, 0, 0);
			x++;
		}
		y++;
	}
	return(image);
}
