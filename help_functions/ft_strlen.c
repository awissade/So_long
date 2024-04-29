/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:26:27 by awissade          #+#    #+#             */
/*   Updated: 2024/03/13 02:45:52 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
	{
		ft_putstr_fd("Error : The map is empty\n", 2);
		exit(1);
	}
	len = 0;
	while (str[len])
		len++;
	return (len);
}
