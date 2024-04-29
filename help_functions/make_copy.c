/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:40:38 by awissade          #+#    #+#             */
/*   Updated: 2024/03/04 15:50:02 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

static size_t	ft_len(char **map_content)
{
	size_t	i;

	i = 0;
	while (map_content[i])
		i++;
	return (i);
}

// This function is just a helper function
// it is the code that inside the if copy is NULL
void	free_copy(char **copy, char **map_content)
{
	ft_putstr_fd("Error : There is an error in the copy of the map\n", 2);
	ft_free_map(copy);
	ft_free_map(map_content);
	exit(1);
}

// This function makes a copy of the map
// It returns a copy of the map
char	**make_copy(char	**map_content)
{
	char	**copy;
	size_t	i;
	size_t	len;

	len = ft_len(map_content);
	copy = (char **)malloc(sizeof(char *) * (len + 1));
	if (!copy)
	{
		ft_putstr_fd("Error : There is an error in the copy of the map\n", 2);
		ft_free_map(map_content);
		exit(1);
	}
	copy[len] = NULL;
	i = 0;
	while (map_content[i])
	{
		copy[i] = ft_strdup(map_content[i]);
		if (!copy[i])
			free_copy(copy, map_content);
		i++;
	}
	return (copy);
}
