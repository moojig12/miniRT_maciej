/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:02:26 by mdomnik           #+#    #+#             */
/*   Updated: 2024/10/10 19:24:11 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int start_mlx(t_render *rnd)
{
	int32_t width = 0;
	int32_t height = 0;
	t_camera cam;

	mlx_get_monitor_size(0, &width, &height);
	if (width == 0 || height == 0)
	{
		width = VP_WIDTH;
		height = VP_HEIGHT;
	}
	rnd->window = mlx_init(width, height, "TriCycles", true);
	rnd->vp_img = mlx_new_image(rnd->window, width, height);
	cam = camera_new(rnd);
	//while (1)
	//{
		if (render(rnd, &cam) == 1)
			return (1);
		mlx_key_hook(rnd->window, &closing_hook, rnd);
		//mlx_key_hook(rnd->window, &movement_hook_press, rnd);
	//}
	return(0);
}


