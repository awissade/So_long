/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:39:55 by awissade          #+#    #+#             */
/*   Updated: 2024/03/15 18:23:03 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

// In this function we need to check if the map rotated by one
size_t	len_of_map(char **map_content)
{
	size_t	i;

	i = 0;
	while (map_content[i])
		i++;
	return (i);
}

void	handle_error(char **map_content)
{
	ft_putstr_fd("Error : The map is not closed\n", 2);
	ft_free_map(map_content);
	exit(1);
}

void	is_map_closed(char **map_content, size_t line_len)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (map_content[i])
	{
		if (map_content[i][0] != '1' || map_content[i][line_len - 1] != '1')
			handle_error(map_content);
		i++;
	}
	len = len_of_map(map_content);
	i = 0;
	while (i < line_len)
	{
		if (map_content[0][i] != '1' || map_content[len - 1][i] != '1')
			handle_error(map_content);
		i++;
	}
}
