/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 01:58:14 by awissade          #+#    #+#             */
/*   Updated: 2024/03/17 15:00:20 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	position_player(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map_content[y])
	{
		x = 0;
		while (data->map_content[y][x])
		{
			if (data->map_content[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	right_and_left(t_game *data, int keycode)
{
	if ((keycode == RIGHT_KEY || keycode == D_KEY)
		&& (data->map_content[data->player.y][data->player.x + 1] != '1'))
	{
		data->player.dx = 1;
		data->player.dy = 0;
		if (data->map_content[data->player.y][data->player.x + 1] != 'E')
			data->player.moves++;
	}
	if ((keycode == LEFT_KEY || keycode == A_KEY)
		&& (data->map_content[data->player.y][data->player.x - 1] != '1'))
	{
		data->player.dx = -1;
		data->player.dy = 0;
		if (data->map_content[data->player.y][data->player.x - 1] != 'E')
			data->player.moves++;
	}
}

static void	up_and_down(t_game *data, int keycode)
{
	if ((keycode == UP_KEY || keycode == W_KEY)
		&& (data->map_content[data->player.y - 1][data->player.x] != '1'))
	{
		data->player.dx = 0;
		data->player.dy = -1;
		if (data->map_content[data->player.y - 1][data->player.x] != 'E')
			data->player.moves++;
	}
	if ((keycode == DOWN_KEY || keycode == S_KEY)
		&& (data->map_content[data->player.y + 1][data->player.x] != '1'))
	{
		data->player.dx = 0;
		data->player.dy = 1;
		if (data->map_content[data->player.y + 1][data->player.x] != 'E')
			data->player.moves++;
	}
}

static void	handle_player_moves(t_game *data)
{
	if (!ft_count(data->map_content, 'C')
		&& data->map_content[data->player.y + data->player.dy]
		[data->player.x + data->player.dx] == 'E')
	{
		write(1, "You win\n", 8);
		close_the_game(data);
	}
	if (data->map_content[data->player.y + data->player.dy]
		[data->player.x + data->player.dx] == 'N')
	{
		write(1, "You lose\n", 9);
		close_the_game(data);
	}
	if (data->map_content[data->player.y + data->player.dy]
		[data->player.x + data->player.dx] != '1'
		&& data->map_content[data->player.y + data->player.dy]
		[data->player.x + data->player.dx] != 'E')
	{
		data->map_content[data->player.y][data->player.x] = '0';
		data->player.y += data->player.dy;
		data->player.x += data->player.dx;
		data->map_content[data->player.y][data->player.x] = 'P';
		data->player.dx = 0;
		data->player.dy = 0;
	}
}

void	move_player_bonus(t_game *data, int keycode)
{
	position_player(data);
	right_and_left(data, keycode);
	up_and_down(data, keycode);
	handle_player_moves(data);
}
