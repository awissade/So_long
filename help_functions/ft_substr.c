/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:49:57 by awissade          #+#    #+#             */
/*   Updated: 2024/02/29 13:53:45 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

char	*ft_substr(const char *map_str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (map_str == NULL)
		return (NULL);
	if (map_str[0] == '\0')
		return ((char *)ft_calloc(1, sizeof(char)));
	if (ft_strlen(map_str) < start)
		sub = (char *)malloc(1 * sizeof(char));
	else if (len < ft_strlen(map_str + start))
		sub = (char *)malloc((len + 1) * sizeof(char));
	else
		sub = (char *)malloc((ft_strlen(map_str + start) + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	if (ft_strlen(map_str) > start)
		while (i < len && map_str[start] != '\0')
			sub[i++] = map_str[start++];
	sub[i] = '\0';
	return (sub);
}
