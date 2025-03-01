/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:41:36 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/17 10:06:31 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	is_collision(t_game *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		if (data->player_x == data->enemies[i].x
			&& data->player_y == data->enemies[i].y)
		{
			ft_printf("Game Over 💀");
			cleanup(data);
			exit(0);
		}
		i++;
	}
}

void	update_enimies_part2(int i, t_game *data, int new_x, int new_y)
{
	is_collision(data);
	if (is_valid_move(data, new_x, new_y))
	{
		data->enemies[i].x = new_x;
		data->enemies[i].y = new_y;
	}
}

void	set_enimie_direction(t_game *data, int i)
{
	if (data->enemies[i].direction == 0)
		data->enimie_img = data->bonus.img_enimy_right;
	else if (data->enemies[i].direction == 1)
		data->enimie_img = data->bonus.img_enimy_left;
	else if (data->enemies[i].direction == 2)
		data->enimie_img = data->bonus.img_enimy_up;
	else if (data->enemies[i].direction == 3)
		data->enimie_img = data->bonus.img_enimy_down;
}

void	update_enimies(t_game *data)
{
	int	i;
	int	new_x;
	int	new_y;

	i = 0;
	while (i < data->enemy_count)
	{
		data->enemies[i].direction = rand() % 4;
		new_x = data->enemies[i].x;
		new_y = data->enemies[i].y;
		if (data->enemies[i].direction == 0)
			new_x++;
		else if (data->enemies[i].direction == 1)
			new_x--;
		else if (data->enemies[i].direction == 2)
			new_y++;
		else if (data->enemies[i].direction == 3)
			new_y--;
		update_enimies_part2(i, data, new_x, new_y);
		i++;
	}
}

void	draw_enemies_bonus(t_game *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		set_enimie_direction(data, i);
		put_image(data, data->enimie_img, data->enemies[i].x,
			data->enemies[i].y);
		i++;
	}
}
