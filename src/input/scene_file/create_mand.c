/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:43:25 by mdomnik           #+#    #+#             */
/*   Updated: 2024/09/09 16:57:51 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

/**
 * @brief Creates objects in the scene based on the provided options.
 *
 * This function iterates through the scene objects array in the options struct
 * and creates the corresponding objects based on their type.
 *
 * @param options The options struct containing the scene objects.
 * @return 0 if all objects are successfully created, -1 otherwise.
 */
int	create_objects(t_options *options)
{
	int	i;

	i = 0;
	while (options->scene.scene_objects[i] != NULL)
	{
		if (ft_strcmp(options->scene.scene_objects[i][0], "A") == 0)
			if (create_ambient(options, options->scene.scene_objects[i]) == -1)
				return (-1);
		if (ft_strcmp(options->scene.scene_objects[i][0], "C") == 0)
			if (create_camera(options, options->scene.scene_objects[i]) == -1)
				return (-1);
		if (ft_strcmp(options->scene.scene_objects[i][0], "L") == 0)
			if (create_light(options, options->scene.scene_objects[i]) == -1)
				return (-1);
		if (check_objects_helper(options, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

/**
 * @brief Helper function to check and create objects in the scene.
 *
 * This function checks the type of object specified in the scene file
 * and calls the respective create function to create the object.
 *
 * @param options A pointer to the options struct.
 * @param i The index of the object in the scene.
 * @return Returns 0 if the object creation is successful, -1 otherwise.
 */
int	check_objects_helper(t_options *options, int i)
{
	if (ft_strcmp(options->scene.scene_objects[i][0], "sp") == 0)
		if (create_sphere(options, options->scene.scene_objects[i]) == -1)
			return (-1);
	if (ft_strcmp(options->scene.scene_objects[i][0], "pl") == 0)
		if (create_plane(options, options->scene.scene_objects[i]) == -1)
			return (-1);
	if (ft_strcmp(options->scene.scene_objects[i][0], "cy") == 0)
		if (create_cylinder(options, options->scene.scene_objects[i]) == -1)
			return (-1);
	return (0);
}

/**
 * Creates an ambient light object and assigns it to the options structure.
 *
 * @param options The options structure to assign the ambient light to.
 * @param args The arguments containing the light ratio and color values.
 * @return 0 on success.
 */
int	create_ambient(t_options *options, char **args)
{
	t_ambient	*ambient;
	char		**colors;

	ambient = gc_malloc(sizeof(t_ambient));
	colors = ft_split(args[2], ',');
	ambient->light_ratio = ft_atob(args[1]);
	ambient->color.r = ft_atoi(colors[0]);
	ambient->color.g = ft_atoi(colors[1]);
	ambient->color.b = ft_atoi(colors[2]);
	options->objects.ambient = ambient;
	return (0);
}

/**
 * Creates a camera object and assigns it to the options structure.
 *
 * @param options The options structure to assign the camera to.
 * @param args The arguments containing the camera coordinates,
 * vector, and field of view.
 * @return 0 if the camera was successfully created and assigned
 */
int	create_camera(t_options *options, char **args)
{
	t_camera	*camera;
	char		**coords;
	char		**vector;

	camera = gc_malloc(sizeof(t_camera));
	coords = ft_split(args[1], ',');
	vector = ft_split(args[2], ',');
	camera->coords.x = ft_atob(coords[0]);
	camera->coords.y = ft_atob(coords[1]);
	camera->coords.z = ft_atob(coords[2]);
	camera->vrange.x = ft_atob(vector[0]);
	camera->vrange.y = ft_atob(vector[1]);
	camera->vrange.z = ft_atob(vector[2]);
	camera->fov = ft_atob(args[3]);
	options->objects.camera = camera;
	return (0);
}

/**
 * Creates a light object and adds it to the options object.
 *
 * @param options The options object to add the light to.
 * @param args The arguments for creating the light.
 *             args[1] - The coordinates of the light (x,y,z).
 *             args[2] - The brightness of the light.
 *             args[3] - The color of the light (r,g,b).
 * @return 0 if the light was successfully created and added
 */
int	create_light(t_options *options, char **args)
{
	t_light		*light;
	char		**coords;
	char		**colors;

	coords = ft_split(args[1], ',');
	colors = ft_split(args[3], ',');
	light = gc_malloc(sizeof(t_light));
	light->coords.x = ft_atob(coords[0]);
	light->coords.y = ft_atob(coords[1]);
	light->coords.z = ft_atob(coords[2]);
	light->color.r = ft_atoi(colors[0]);
	light->color.g = ft_atoi(colors[1]);
	light->color.b = ft_atoi(colors[2]);
	light->brightness = ft_atob(args[2]);
	options->objects.light = append_light_list(options->objects.light, light);
	return (0);
}