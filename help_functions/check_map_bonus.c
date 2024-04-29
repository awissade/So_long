/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 03:48:39 by awissade          #+#    #+#             */
/*   Updated: 2024/03/14 17:13:57 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

char	**check_map_bonus(char *map, t_game *data)
{
	char	*str;
	char	**map_content;

	if (ft_strstr(map, ".ber") == 1)
	{
		ft_putstr_fd("Error : Map is invalid\n", 2);
		exit (1);
	}
	str = read_file_contents(map);
	check_for_multiple_line(str);
	map_content = ft_split(str, '\n');
	free(str);
	is_map_equal(map_content);
	contents_checker_bonus(map_content, data);
	return (map_content);
}
