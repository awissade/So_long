/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:38:01 by awissade          #+#    #+#             */
/*   Updated: 2024/03/08 17:32:15 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

void	check_valid_path(char **copy, char **map_content)
{
	if (ft_count(copy, 'C') != 0 || ft_count(copy, 'E') == 1)
	{
		ft_putstr_fd("Error : There is no valid path\n", 2);
		ft_free_map(copy);
		ft_free_map(map_content);
		exit(1);
	}
}
