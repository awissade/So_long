/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:11:34 by awissade          #+#    #+#             */
/*   Updated: 2024/03/17 19:53:53 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./so_long.h"

char	**check_map_bonus(char *map, t_game *data);
void	contents_checker_bonus(char **map_content, t_game *data);
void	create_the_game_bonus(t_game *data);
void	load_images_bonus(t_game *data);
void	draw_map_bonus(t_game *data, char **map_content);
void	move_player_bonus(t_game *data, int keycode);
void	create_the_window_bonus(t_game *data);
void	update(t_game *data);
void	check_path_bonus(char **map_content);

#endif
