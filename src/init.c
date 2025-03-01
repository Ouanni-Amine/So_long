/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:31 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/16 18:25:49 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_game *data)
{
	*data = (t_game){0};
	data->img_size = 32;
}

void	load_player_side_images(t_game *data)
{
	int	h;
	int	w;

	data->right_side = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_semi_right.xpm", &w, &h);
	data->left_side = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_semi_left.xpm", &w, &h);
	data->up_side = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_semi_up.xpm", &w, &h);
	data->down_side = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_semi_down.xpm", &w, &h);
}

int	load_images(t_game *data)
{
	int		h;
	int		w;

	data->wall_path = "sprites/Other/Walls/wall.xpm";
	data->player_path = "sprites/Pac-Man/pac_closed.xpm";
	data->coin_path = "sprites/Other/Pacdots/pacdot_powerup.xpm";
	data->exit_path = "sprites/Other/Portal/portal.xpm";
	load_player_side_images(data);
	data->wall_img = mlx_xpm_file_to_image(data->mlx, data->wall_path, &w, &h);
	data->player_img = mlx_xpm_file_to_image(data->mlx,
			data->player_path, &w, &h);
	data->old_img = data->player_img;
	data->coin_img = mlx_xpm_file_to_image(data->mlx, data->coin_path, &w, &h);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, data->exit_path, &w, &h);
	if (!data->wall_img || !data->coin_img || !data->exit_img
		||!data->player_img || !data->right_side || !data->left_side
		|| !data->up_side || !data->down_side)
	{
		ft_putstr_fd ("Error\nFaild loading images", 2);
		return (0);
	}
	return (1);
}

int	init_game(t_game *data)
{
	int	size;

	size = data->img_size;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, data->map_w * size,
			data->map_h * size, "So_long");
	if (!data->win)
		return (0);
	if (!load_images(data))
		return (0);
	return (1);
}
