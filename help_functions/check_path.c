/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:29:10 by awissade          #+#    #+#             */
/*   Updated: 2024/03/17 23:41:44 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_path(char **map_content)
{
	char	**copy;

	copy = make_copy(map_content);
	flood_fill(copy);
	check_valid_path(copy, map_content);
	ft_free_map(copy);
}
