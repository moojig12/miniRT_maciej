/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:58:36 by astavrop          #+#    #+#             */
/*   Updated: 2024/08/26 17:28:30 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vec3.h"
# include "ray.h"

# define R 0
# define G 1
# define B 2

typedef struct s_vec3	t_color;

t_color		ray_color(t_ray *r);
int			write_color(int fd, t_color *pixel_color);
t_color		per_pixel(t_ray ray);

#endif /* COLOR_H */