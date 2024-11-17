/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:36:58 by astavrop          #+#    #+#             */
/*   Updated: 2024/11/17 16:06:17 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include "../../inc/parser.h"

#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

bool	is_valid_filename(char *filename)
{
	int		fn_len;

	fn_len = ft_strlen(filename);
	if (filename[fn_len] == 't' && filename[fn_len - 1] == 'r'
		&& filename[fn_len - 2] == '.')
		return (true);
	ft_dprintf(2, "Error [parser]: invalid file extension.");
	return (false);
}

bool	has_valid_perms(char *filename)
{
	int	tmpfd;

	tmpfd = open(filename, O_RDONLY);
	if (tmpfd < 0)
	{
		perror("Error [parser]");
		return (false);
	}
	close(tmpfd);
	return (true);
}

