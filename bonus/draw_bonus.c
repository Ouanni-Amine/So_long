/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:43:04 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/16 17:29:16 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image(t_game *data, void *img, int x, int y)
{
	int	size;

	size = data->img_size;
	mlx_put_image_to_window(data->mlx, data->win, img, x * size, y * size);
}

void	draw_bonus(t_game *data)
{
	draw_player_bonus (data);
	draw_enemies_bonus (data);
}

void	count_despliyer(t_game *data)
{
	char	*str;

	str = ft_itoa(data->moves);
	if (!str)
	{
		cleanup(data);
		exit(0);
	}
	mlx_string_put(data->mlx, data->win, data->map_w, data->map_h,
		0xFFFF00, str);
	free(str);
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
	draw_bonus(data);
	count_despliyer(data);
}
