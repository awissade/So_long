/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:01:49 by awissade          #+#    #+#             */
/*   Updated: 2024/02/29 15:01:53 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

void	check_for_screen_size(char **map_content, int first_line_len)
{
	unsigned int	len;

	if (first_line_len > 96)
	{
		ft_putstr_fd("Error : The map is so big for the window\n", 2);
		ft_free_map(map_content);
		exit (1);
	}
	len = 0;
	while (map_content[len])
		len++;
	if (len > 50)
	{
		ft_putstr_fd("Error : The map is so big for the window\n", 2);
		ft_free_map(map_content);
		exit (1);
	}
}

// In this function we need to check if the map is equal
// And then we need to check if the map is closed
void	is_map_equal(char **map_content)
{
	size_t	first_line_len;
	int		i;

	i = 0;
	first_line_len = ft_strlen(map_content[0]);
	check_for_screen_size(map_content, first_line_len);
	while (map_content[i])
	{
		if (ft_strlen(map_content[i]) != first_line_len)
		{
			ft_putstr_fd("Error : The map is not correct\n", 2);
			ft_free_map(map_content);
			exit(1);
		}
		i++;
	}
	is_map_closed(map_content, first_line_len);
}
