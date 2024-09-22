/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:06:12 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/22 17:02:31 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "mrt.h"
#include "vec3.h"

# define MAX_DEPTH 5
# define IMG_FOV 70
# define PI 3.141592653589793238462643383279502884197

typedef struct s_camera	t_camera;

struct	s_camera
{
	t_point3	center; // camera position
	t_point3	dir; // camera direction
	float		FOV; // field of view [0, 180]
	
	t_vec3		pix_du; // horizontal pixel offest
	t_vec3		pix_dv; // vertical pixel offest
	t_vec3		horiz;
	t_vec3		vert;
	t_vec3		llc; // left lower corner
	float		aspect_ratio; // width / height
	float		focal_dist;
	float		pix_size;
	float		vp_width;
	float		vp_height;
	int			img_width; // image width
	int			img_height; // image height
	int			max_depth; // amount of bounces
};

/* Utility functions */

t_camera	camera_new(t_render *rnd);
double			deg_to_rad(double deg);

#endif /* CAMERA_H */
