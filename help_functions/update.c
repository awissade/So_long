/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:43:42 by awissade          #+#    #+#             */
/*   Updated: 2024/03/15 16:47:46 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	update(t_game *data)
{
	if (data->delay == 6)
	{
		data->animation_frame++;
		if (data->animation_frame == 4)
			data->animation_frame = 0;
		data->delay = 0;
	}
	data->delay++;
}
