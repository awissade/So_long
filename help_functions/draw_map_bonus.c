/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:45:47 by awissade          #+#    #+#             */
/*   Updated: 2024/03/17 03:41:39 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	draw_image(t_game *game, t_data *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img->img, x * 30, y * 30);
}

void	draw_element(t_game *data, char **map, int x, int y)
{
	if (map[y][x] == '1')
		draw_image(data, &data->wall, x, y);
	if (map[y][x] != '1')
		draw_image(data, &data->floor, x, y);
	if (map[y][x] == 'C')
		draw_image(data, &data->collectible, x, y);
	if (map[y][x] == 'E' && ft_count(map, 'C') > 0)
		draw_image(data, &data->exit.images[0], x, y);
	if (map[y][x] == 'E' && ft_count(map, 'C') == 0)
		draw_image(data, &data->exit.images[1], x, y);
	if (map[y][x] == 'P')
		draw_image(data, &data->player.images[0], x, y);
	if (map[y][x] == 'N')
		draw_image(data, &data->enemy.images[data->animation_frame], x, y);
}

void	draw_map_bonus(t_game *data, char **map_content)
{
	char	*str;
	int		x;
	int		y;

	y = 0;
	while (map_content[y])
	{
		x = 0;
		while (map_content[y][x])
		{
			draw_element(data, map_content, x, y);
			x++;
		}
		y++;
	}
	str = ft_itoa(data->player.moves);
	mlx_string_put(data->mlx, data->win, 10, 5, 0xFFFFFFF, str);
	free(str);
}
