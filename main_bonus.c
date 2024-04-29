/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 03:32:15 by awissade          #+#    #+#             */
/*   Updated: 2024/03/17 03:39:37 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	key_hook(int keycode, t_game *data)
{
	if (keycode == ESC_KEY)
		close_the_game(data);
	if (keycode == UP_KEY || keycode == DOWN_KEY
		|| keycode == LEFT_KEY || keycode == RIGHT_KEY || keycode == W_KEY
		|| keycode == S_KEY || keycode == A_KEY || keycode == D_KEY)
	{
		move_player_bonus(data, keycode);
		create_the_game_bonus(data);
	}
	return (0);
}

int	x_botton(t_game *data)
{
	close_the_game(data);
	return (0);
}

int	handle_animation(t_game *data)
{
	update(data);
	create_the_game_bonus(data);
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
	data.map_content = check_map_bonus(av[1], &data);
	check_path_bonus(data.map_content);
	create_the_game_bonus(&data);
	mlx_loop_hook(data.mlx, handle_animation, &data);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 17, x_botton, &data);
	mlx_loop(data.mlx);
	return (0);
}
