/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:57:31 by awissade          #+#    #+#             */
/*   Updated: 2024/03/04 15:49:38 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*copy;

	copy = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!copy)
	{
		ft_putstr_fd("Error : There is an error in the copy of the map\n", 2);
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
