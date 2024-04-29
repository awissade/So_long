/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:05:06 by awissade          #+#    #+#             */
/*   Updated: 2024/03/17 17:07:56 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

static void	fill_map(char **copy, int i, int j)
{
	if (copy[j][i] == '1' || copy[j][i] == 'F' || copy[j][i] == 'N')
		return ;
	if (copy[j][i] == 'E')
	{
		copy[j][i] = 'F';
		return ;
	}
	copy[j][i] = 'F';
	fill_map(copy, i + 1, j);
	fill_map(copy, i - 1, j);
	fill_map(copy, i, j + 1);
	fill_map(copy, i, j - 1);
}

// This function will be used for locate the player position
void	flood_fill_bonus(char **copy)
{
	int	i;
	int	j;

	j = 0;
	while (copy[j])
	{
		i = 0;
		while (copy[j][i])
		{
			if (copy[j][i] == 'P')
			{
				fill_map(copy, i, j);
				return ;
			}
			i++;
		}
		j++;
	}
}
