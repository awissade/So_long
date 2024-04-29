/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:04:28 by awissade          #+#    #+#             */
/*   Updated: 2024/03/17 03:41:15 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

static char	*string(char *tab, long num, int signe, int i)
{
	int	j;

	if (!tab)
		return (NULL);
	j = 0;
	if (num * signe < 0)
	{
		tab[j] = '-';
		j++;
	}
	while (i > 0)
	{
		tab[j] = '0' + (num / i);
		num = num % i;
		i /= 10;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

static char	*ft_allocate(long num, int signe, int len)
{
	char	*tab;

	if (num * signe < 0)
	{
		len = len + 2;
		tab = (char *)malloc(len * sizeof(char));
	}
	else
	{
		len = len + 1;
		tab = (char *)malloc(len * sizeof(char));
	}
	if (!tab)
		return (NULL);
	return (tab);
}

char	*ft_itoa(int n)
{
	long	num;
	int		signe;
	long	i;
	int		len;

	num = n;
	signe = 1;
	if (num < 0)
	{
		signe = -signe;
		num = -num;
	}
	len = 1;
	i = 1;
	while (num / i >= 10)
	{
		i *= 10;
		len++;
	}
	return (string(ft_allocate(num, signe, len), num, signe, i));
}
