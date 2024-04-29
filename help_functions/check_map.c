/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:50:45 by awissade          #+#    #+#             */
/*   Updated: 2024/03/13 02:38:35 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**check_map(char *map)
{
	char	*str;
	char	**map_content;

	if (ft_strstr(map, ".ber") == 1)
	{
		ft_putstr_fd("Error : Map is invalid\n", 2);
		exit(1);
	}
	str = read_file_contents(map);
	check_for_multiple_line(str);
	map_content = ft_split(str, '\n');
	free(str);
	is_map_equal(map_content);
	contents_checker(map_content);
	return (map_content);
}
