/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_checker_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:59:04 by awissade          #+#    #+#             */
/*   Updated: 2024/03/14 17:14:11 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	check_map_contents(char **map_content, t_game *data)
{
	if (data->e != 1)
	{
		ft_putstr_fd("Error : The map must have one exit\n", 2);
		ft_free_map(map_content);
		exit(1);
	}
	if (data->p != 1)
	{
		ft_putstr_fd("Error : The map must have one player\n", 2);
		ft_free_map(map_content);
		exit(1);
	}
	if (data->c < 1)
	{
		ft_putstr_fd("Error : The map must have at least one collectible\n", 2);
		ft_free_map(map_content);
		exit(1);
	}
}

static int	check_the_elements(char character, t_game *data)
{
	if (character == 'C')
		data->c += 1;
	else if (character == 'E')
		data->e += 1;
	else if (character == 'P')
		data->p += 1;
	else if (character == 'N')
		data->x += 1;
	else if (character == '1' || character == '0')
		;
	else
	{
		ft_putstr_fd("Error : The map must have only 1, 0, C, E, P, N\n", 2);
		return (1);
	}
	return (0);
}

void	contents_checker_bonus(char **map_content, t_game *data)
{
	int	i;
	int	j;

	j = 0;
	while (map_content[j])
	{
		i = 0;
		while (map_content[j][i])
		{
			if (check_the_elements(map_content[j][i], data) == 1)
			{
				ft_free_map(map_content);
				exit(1);
			}
			i++;
		}
		j++;
	}
	check_map_contents(map_content, data);
}
