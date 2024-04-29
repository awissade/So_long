/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:08:28 by awissade          #+#    #+#             */
/*   Updated: 2024/03/17 19:54:23 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

void	check_valid_path_bonus(char **copy, char **map_content)
{
	if (ft_count(copy, 'C') != 0 || ft_count(copy, 'E') == 1)
	{
		ft_putstr_fd("Error : There is no valid path\n", 2);
		ft_free_map(copy);
		ft_free_map(map_content);
		exit(1);
	}
}
