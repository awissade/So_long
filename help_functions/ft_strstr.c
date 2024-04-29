/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:01:17 by awissade          #+#    #+#             */
/*   Updated: 2024/03/13 02:45:30 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int	ft_strstr(char *str, char *sub)
{
	int	i;
	int	j;

	i = 0;
	if (!str || !sub)
		return (1);
	while (str[i])
	{
		j = 0;
		while (sub[j] && str[i + j] == sub[j])
		{
			j++;
			if (!sub[j] && !str[i + j])
				return (0);
		}
		i++;
	}
	return (1);
}
