/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:26:08 by awissade          #+#    #+#             */
/*   Updated: 2024/02/29 17:26:11 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

void	check_map_contents(char **map_content, int c, int e, int p)
{
	if (e != 1)
	{
		ft_putstr_fd("Error : The map must have one exit\n", 2);
		ft_free_map(map_content);
		exit(1);
	}
	if (p != 1)
	{
		ft_putstr_fd("Error : The map must have one player\n", 2);
		ft_free_map(map_content);
		exit(1);
	}
	if (c < 1)
	{
		ft_putstr_fd("Error : The map must have at least one collectible\n", 2);
		ft_free_map(map_content);
		exit(1);
	}
}

int	check_the_elements(char character, int *c, int *e, int *p)
{
	if (character == 'C')
		*c += 1;
	else if (character == 'E')
		*e += 1;
	else if (character == 'P')
		*p += 1;
	else if (character == '1' || character == '0')
		;
	else
	{
		ft_putstr_fd("Error : The map must have only 1, 0, C, E, P\n", 2);
		return (1);
	}
	return (0);
}

void	contents_checker(char **map_content)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;

	j = 0;
	c = 0;
	e = 0;
	p = 0;
	while (map_content[j])
	{
		i = 0;
		while (map_content[j][i])
		{
			if (check_the_elements(map_content[j][i], &c, &e, &p) == 1)
			{
				ft_free_map(map_content);
				exit(1);
			}
			i++;
		}
		j++;
	}
	check_map_contents(map_content, c, e, p);
}
