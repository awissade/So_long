/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:37:11 by awissade          #+#    #+#             */
/*   Updated: 2024/03/15 18:23:41 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	load_image(t_data *image_ptr, char *path, t_game *game)
{
	image_ptr->img = mlx_xpm_file_to_image(game->mlx, path,
			&image_ptr->width, &image_ptr->height);
	if (image_ptr->img == NULL)
	{
		ft_putstr_fd("Error : Image not found\n", 2);
		close_the_game(game);
		exit(1);
	}
}

void	load_images_bonus(t_game *game)
{
	load_image(&game->wall, "textures/wall.xpm", game);
	load_image(&game->floor, "textures/floor.xpm", game);
	load_image(&game->collectible, "textures/collectible.xpm", game);
	load_image(&game->exit.images[0], "textures/exit1.xpm", game);
	load_image(&game->exit.images[1], "textures/exit2.xpm", game);
	load_image(&game->player.images[0], "textures/player.xpm", game);
	load_image(&game->enemy.images[0], "textures/enemy0.xpm", game);
	load_image(&game->enemy.images[1], "textures/enemy1.xpm", game);
	load_image(&game->enemy.images[2], "textures/enemy2.xpm", game);
	load_image(&game->enemy.images[3], "textures/enemy3.xpm", game);
}
