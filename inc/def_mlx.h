/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_mlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:08:52 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/10 19:12:44 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_MLX_H
# define DEF_MLX_H

//mlx_handle/mlx_init.c
int start_mlx(t_render *render);

//mlx_handle/mlx_hooks.c
void closing_hook(mlx_key_data_t keydata, void *param);
void movement_hook_press(mlx_key_data_t keydata, void *param);
void movement_hook_hold(mlx_key_data_t keydata, void *param);
#endif /* DEF_MLX_H */