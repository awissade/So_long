/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_the_game_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:44:49 by awissade          #+#    #+#             */
/*   Updated: 2024/03/14 20:48:26 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	create_the_game_bonus(t_game *data)
{
	if (data->temp == 0)
	{
		create_the_window_bonus(data);
		load_images_bonus(data);
		data->temp = 1;
	}
	draw_map_bonus(data, data->map_content);
}
