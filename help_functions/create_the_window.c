/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_the_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:05:29 by awissade          #+#    #+#             */
/*   Updated: 2024/03/12 22:39:10 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	lenght_of_map(char **map, int *x, int *y)
{
	*x = ft_strlen(map[0]);
	*y = 0;
	while (map[*y])
		*y += 1;
}

void	create_the_window(t_game *data)
{
	int	x;
	int	y;

	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putstr_fd("Error : mlx_init() failed\n", 2);
		close_the_game(data);
		exit(1);
	}
	lenght_of_map(data->map_content, &x, &y);
	data->win = mlx_new_window(data->mlx, x * 30, y * 30, "so_long");
	if (!data->win)
	{
		ft_putstr_fd("Error : mlx_new_window() failed\n", 2);
		close_the_game(data);
		exit(1);
	}
}
