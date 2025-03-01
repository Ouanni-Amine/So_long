/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:10:22 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/14 19:23:49 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *data, void *img, int x, int y)
{
	int	size;

	size = data->img_size;
	mlx_put_image_to_window(data->mlx, data->win, img, x * size, y * size);
}

void	draw(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(data->mlx, data->win);
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (data->map[y][x] == '1')
				put_image(data, data->wall_img, x, y);
			else if (data->map[y][x] == 'C')
			{
				put_image(data, data->coin_img, x, y);
			}
			else if (y == data->exit_y && x == data->exit_x
				&& data->collected == data->coins)
				put_image(data, data->exit_img, x, y);
			x++;
		}
		y++;
	}
	put_image(data, data->player_img, data->player_x, data->player_y);
}
