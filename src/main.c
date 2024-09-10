/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:06:31 by astavrop          #+#    #+#             */
/*   Updated: 2024/09/10 18:50:45 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mrt.h"

int main(int argc, char **argv)
{
	t_render	render;
	
	if(check_args(argc, argv, &render) == 1)
		return(1);
	if(start_mlx(&render) == 1)
		return(1);
	printf_option_values(render.options);
	printf_objects(render.options);
	mlx_loop(render.window);
}
