/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:33:04 by awissade          #+#    #+#             */
/*   Updated: 2024/03/17 03:40:15 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_image(t_game *game, t_data *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img->img, x * 30, y * 30);
}

void	draw_map(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_image(game, &game->wall, x, y);
			if (map[y][x] != '1')
				draw_image(game, &game->floor, x, y);
			if (map[y][x] == 'C')
				draw_image(game, &game->collectible, x, y);
			if (map[y][x] == 'E' && ft_count(map, 'C') > 0)
				draw_image(game, &game->exit.images[0], x, y);
			if (map[y][x] == 'E' && ft_count(map, 'C') == 0)
				draw_image(game, &game->exit.images[1], x, y);
			if (map[y][x] == 'P')
				draw_image(game, &game->player.images[0], x, y);
			x++;
		}
		y++;
	}
}
