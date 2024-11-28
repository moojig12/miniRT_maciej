/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_world.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:40:41 by mdomnik           #+#    #+#             */
/*   Updated: 2024/11/28 23:03:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_WORLD_H
# define DEF_WORLD_H

//operations/world/create.c
t_x		intersect_world(t_world *world, t_ray ray);
t_comp prepare_computations(t_i i, t_ray ray);
t_color3 shade_hit(t_world *world, t_comp comps, int remaining);
t_color3 color_at(t_world *world, t_ray ray, int remaining);
t_matrix view_transformation(t_point3 from, t_point3 to, t_vec3 up);
t_camera	*camera_new(int hsize, int vsize, float fov);
t_ray ray_for_pixel(t_camera *camera, int px, int py);
mlx_image_t *render(t_camera *camera, t_world *world, mlx_image_t *image);
bool is_shadowed(t_world *world, t_point3 light_pos, t_point3 point);
#endif
