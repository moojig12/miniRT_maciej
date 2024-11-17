/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:37:17 by astavrop          #+#    #+#             */
/*   Updated: 2024/11/17 17:09:46 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdbool.h>
#include <stddef.h>

bool	is_valid_filename(char *filename);
bool	has_valid_perms(char *filename);

float	ft_atof(char *line, size_t start);

#endif /* PARSER_H */
