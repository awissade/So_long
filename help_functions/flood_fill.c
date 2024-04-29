/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:03:39 by awissade          #+#    #+#             */
/*   Updated: 2024/03/15 18:22:37 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

void	fill_map(char **copy, int i, int j)
{
	if (copy[j][i] == '1' || copy[j][i] == 'F')
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
void	flood_fill(char **copy)
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
