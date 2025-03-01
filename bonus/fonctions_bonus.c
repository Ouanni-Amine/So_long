/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:00:27 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/17 10:06:26 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_player_direction(t_game *data)
{
	if (data->bonus.animation_state == 0)
		data->player_img = data->bonus.img_closed;
	else if (data->bonus.direction == 2 && data->bonus.animation_state == 1)
		data->player_img = data->bonus.img_semi_open_left;
	else if (data->bonus.direction == 2)
		data->player_img = data->bonus.img_full_open_left;
	else if (data->bonus.direction == 1 && data->bonus.animation_state == 1)
		data->player_img = data->bonus.img_semi_open_right;
	else if (data->bonus.direction == 1)
		data->player_img = data->bonus.img_full_open_right;
	else if (data->bonus.direction == 3 && data->bonus.animation_state == 1)
		data->player_img = data->bonus.img_semi_open_up;
	else if (data->bonus.direction == 3)
		data->player_img = data->bonus.img_full_open_up;
	else if (data->bonus.direction == 4 && data->bonus.animation_state == 1)
		data->player_img = data->bonus.img_semi_open_down;
	else if (data->bonus.direction == 4)
		data->player_img = data->bonus.img_full_open_down;
	else
		data->player_img = data->bonus.img_closed;
}

void	draw_player_bonus(t_game *data)
{
	set_player_direction(data);
	put_image(data, data->player_img, data->player_x, data->player_y);
}

void	enemy_position(t_game *data)
{
	int	index;
	int	x;
	int	y;

	index = 0;
	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (data->map[y][x] == 'M')
			{
				data->enemies[index].x = x;
				data->enemies[index].y = y;
				data->enemies[index].direction = rand() % 4;
				index ++;
			}
			x++;
		}
		y++;
	}
}

int	init_enemies(t_game *data)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	index = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (data->map[y][x] == 'M')
				data->enemy_count++;
			x++;
		}
		y++;
	}
	data->enemies = malloc (sizeof (t_enimy) * data->enemy_count);
	if (!data->enemies)
		return (0);
	enemy_position(data);
	return (1);
}
