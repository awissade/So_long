/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_the_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 01:34:14 by awissade          #+#    #+#             */
/*   Updated: 2024/03/17 17:19:07 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_map_content(char **map_content)
{
	int	i;

	i = 0;
	while (map_content[i])
	{
		free (map_content[i]);
		i++;
	}
	free (map_content);
}

static void	destroy_the_images(t_game *data)
{
	if (data->wall.img)
		mlx_destroy_image(data->mlx, data->wall.img);
	if (data->floor.img)
		mlx_destroy_image(data->mlx, data->floor.img);
	if (data->collectible.img)
		mlx_destroy_image(data->mlx, data->collectible.img);
	if (data->exit.images[0].img)
		mlx_destroy_image(data->mlx, data->exit.images[0].img);
	if (data->exit.images[1].img)
		mlx_destroy_image(data->mlx, data->exit.images[1].img);
	if (data->player.images[0].img)
		mlx_destroy_image(data->mlx, data->player.images[0].img);
	if (data->enemy.images[0].img)
		mlx_destroy_image(data->mlx, data->enemy.images[0].img);
	if (data->enemy.images[1].img)
		mlx_destroy_image(data->mlx, data->enemy.images[1].img);
	if (data->enemy.images[2].img)
		mlx_destroy_image(data->mlx, data->enemy.images[2].img);
	if (data->enemy.images[3].img)
		mlx_destroy_image(data->mlx, data->enemy.images[3].img);
}

static void	distroy_the_display(t_game *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
}

void	close_the_game(t_game *data)
{
	if (data->map_content)
		free_map_content(data->map_content);
	destroy_the_images(data);
	distroy_the_display(data);
	ft_putstr_fd("See you later !\n", 1);
	exit(0);
}
