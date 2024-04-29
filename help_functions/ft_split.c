/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:55:40 by awissade          #+#    #+#             */
/*   Updated: 2024/02/29 14:46:13 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

void	ft_free(char **map_content, int j)
{
	while (j >= 0)
	{
		free(map_content[j]);
		j--;
	}
	free(map_content);
	ft_putstr_fd("Error : There is an error in reading the map\n", 2);
	exit(1);
}

int	len(const char *map_str, char c)
{
	size_t	len;

	len = 0;
	while (map_str[len] && map_str[len] != c)
		len++;
	return (len);
}

int	count_word(const char *map_str, char c)
{
	int	in_word;
	int	count;
	int	i;

	in_word = 0;
	count = 0;
	i = 0;
	while (map_str[i] == c)
		i++;
	while (map_str[i])
	{
		if (map_str[i] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

char	**second_split(const char *map_str, char **map_content, char c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (map_str[i])
	{
		while (map_str[i] == c && map_str[i])
			i++;
		if (map_str[i])
		{
			map_content[j] = ft_substr(map_str, i, len(map_str + i, c));
			if (!map_content[j])
				ft_free(map_content, j);
			j++;
		}
		while (map_str[i] && map_str[i] != c)
			i++;
	}
	map_content[j] = NULL;
	return (map_content);
}

char	**ft_split(const char *map_str, char c)
{
	char	**map_content;

	map_content = (char **)malloc((count_word(map_str, c) + 1)
			* sizeof(char *));
	if (map_content == NULL)
	{
		ft_putstr_fd("Error : There is an error in reading the map\n", 2);
		exit(1);
	}
	return (second_split(map_str, map_content, c));
}
