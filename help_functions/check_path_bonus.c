/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:56:19 by awissade          #+#    #+#             */
/*   Updated: 2024/03/17 17:04:41 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_path_bonus(char **map_content)
{
	char	**copy;

	copy = make_copy(map_content);
	flood_fill_bonus(copy);
	check_valid_path_bonus(copy, map_content);
	ft_free_map(copy);
}
