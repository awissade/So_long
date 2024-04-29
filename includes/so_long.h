/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:12:47 by awissade          #+#    #+#             */
/*   Updated: 2024/03/16 17:36:56 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "keys.h"
# include "functions.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	int		height;
	int		width;
	int		count;
}	t_data;

typedef struct s_player
{
	t_data	images[4];
	int		moves;
	int		x;
	int		y;
	int		dx;
	int		dy;
}	t_multi;

typedef struct s_game
{
	char		**map_content;
	void		*mlx;
	void		*win;
	int			c;
	int			e;
	int			p;
	int			x;
	t_data		wall;
	t_data		floor;
	t_multi		exit;
	t_data		collectible;
	t_multi		player;
	t_multi		enemy;
	int			animation_frame;
	int			delay;
	int			temp;
}	t_game;

char	**check_map(char *map);
void	is_map_equal(char **map_content);
void	is_map_closed(char **map_content, size_t line_len);
void	contents_checker(char **map_content);
void	check_path(char **map_content);
void	create_the_game(t_game *data);
void	create_the_window(t_game *data);
void	load_images(t_game *game);
void	draw_map(t_game *game, char **map);
void	move_player(t_game *data, int keycode);
void	close_the_game(t_game *data);

#endif