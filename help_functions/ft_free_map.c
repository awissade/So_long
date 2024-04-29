/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:06:51 by awissade          #+#    #+#             */
/*   Updated: 2024/03/04 15:50:53 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

void	ft_free_map(char **map_content)
{
	int	i;

	i = 0;
	while (map_content[i])
	{
		free(map_content[i]);
		i++;
	}
	free(map_content);
}
