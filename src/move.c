/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:01:41 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/14 19:07:14 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_position(t_game *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] == 'C')
	{
		data->map[new_y][new_x] = '0';
		data->collected++;
	}
	data->player_x = new_x;
	data->player_y = new_y;
	data->moves++;
	ft_printf ("Move number :%d\n", data->moves);
	if (data->collected == data->coins && data->player_x == data->exit_x
		&& data->player_y == data->exit_y)
	{
		ft_printf("Congratulations you won 🏆");
		cleanup (data);
		exit (0);
	}
}

int	is_valid_move(t_game *data, int new_x, int new_y)
{
	return (new_x >= 0 && new_x < data->map_w && new_y >= 0
		&& new_y < data->map_h && data->map[new_y][new_x] != '1' );
}

void	update_player_img(t_game *data, int key)
{
	if (key == 124)
		data->player_img = data->right_side;
	else if (key == 123)
		data->player_img = data->left_side;
	else if (key == 126)
		data->player_img = data->up_side;
	else if (key == 125)
		data->player_img = data->down_side;
}

void	move_player(int key, t_game *data)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x;
	new_y = data->player_y;
	if (key == 124)
		new_x++;
	else if (key == 123)
		new_x--;
	else if (key == 126)
		new_y--;
	else if (key == 125)
		new_y++;
	update_player_img(data, key);
	if (is_valid_move(data, new_x, new_y))
		update_position(data, new_x, new_y);
	draw(data);
}
