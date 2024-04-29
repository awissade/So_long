/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:31:48 by awissade          #+#    #+#             */
/*   Updated: 2024/03/13 02:52:07 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

// This function is for handling the key events
int	key_hook(int keycode, t_game *data)
{
	if (keycode == ESC_KEY)
		close_the_game(data);
	if (keycode == UP_KEY || keycode == DOWN_KEY
		|| keycode == LEFT_KEY || keycode == RIGHT_KEY || keycode == W_KEY
		|| keycode == S_KEY || keycode == A_KEY || keycode == D_KEY)
	{
		move_player(data, keycode);
		draw_map(data, data->map_content);
	}
	return (0);
}

// This function is for the x_botton on the top right of the window
int	x_botton(t_game *data)
{
	close_the_game(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
	{
		ft_putstr_fd("Error : Wrong number of arguments\n", 2);
		return (1);
	}
	ft_memset(&data, 0, sizeof(t_game));
	data.map_content = check_map(av[1]);
	check_path(data.map_content);
	create_the_game(&data);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 17, x_botton, &data);
	mlx_loop(data.mlx);
	return (0);
}
