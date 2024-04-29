/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:59:43 by awissade          #+#    #+#             */
/*   Updated: 2024/03/12 22:40:26 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_image(t_data *image_ptr, char *path, t_game *game)
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

void	load_images(t_game *game)
{
	load_image(&game->wall, "textures/wall.xpm", game);
	load_image(&game->floor, "textures/floor.xpm", game);
	load_image(&game->collectible, "textures/collectible.xpm", game);
	load_image(&game->exit.images[0], "textures/exit1.xpm", game);
	load_image(&game->exit.images[1], "textures/exit2.xpm", game);
	load_image(&game->player.images[0], "textures/player.xpm", game);
}
