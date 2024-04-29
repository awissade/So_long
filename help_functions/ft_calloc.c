/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:14:37 by awissade          #+#    #+#             */
/*   Updated: 2024/02/28 14:43:30 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*tab;
	size_t	i;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	total_size = count * size;
	tab = malloc(total_size);
	if (!tab)
		return (NULL);
	i = 0;
	ft_memset(tab, 0, total_size);
	return ((void *)tab);
}
