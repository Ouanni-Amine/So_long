/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:31 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/16 18:28:37 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_vars(t_game *data)
{
	*data = (t_game){0};
	data->img_size = 32;
}

void	load_enimies_images(t_game *data)
{
	int	h;
	int	w;

	data->bonus.img_enimy_down = mlx_xpm_file_to_image(data->mlx,
			"sprites/Ghosts/B/ghost_down1.xpm", &w, &h);
	data->bonus.img_enimy_up = mlx_xpm_file_to_image(data->mlx,
			"sprites/Ghosts/B/ghost_up1.xpm", &w, &h);
	data->bonus.img_enimy_left = mlx_xpm_file_to_image(data->mlx,
			"sprites/Ghosts/B/ghost_left1.xpm", &w, &h);
	data->bonus.img_enimy_right = mlx_xpm_file_to_image(data->mlx,
			"sprites/Ghosts/B/ghost_right1.xpm", &w, &h);
}

void	load_player_side_images(t_game *data)
{
	int	h;
	int	w;

	data->bonus.img_closed = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_closed.xpm", &w, &h);
	data->bonus.img_full_open_down = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_open_down.xpm", &w, &h);
	data->bonus.img_full_open_left = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_open_left.xpm", &w, &h);
	data->bonus.img_full_open_right = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_open_right.xpm", &w, &h);
	data->bonus.img_full_open_up = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_open_up.xpm", &w, &h);
	data->bonus.img_semi_open_down = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_semi_down.xpm", &w, &h);
	data->bonus.img_semi_open_left = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_semi_left.xpm", &w, &h);
	data->bonus.img_semi_open_right = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_semi_right.xpm", &w, &h);
	data->bonus.img_semi_open_up = mlx_xpm_file_to_image(data->mlx,
			"sprites/Pac-Man/pac_semi_up.xpm", &w, &h);
}

int	load_images(t_game *data)
{
	int		h;
	int		w;

	data->wall_path = "sprites/Other/Walls/wall.xpm";
	data->coin_path = "sprites/Other/Pacdots/pacdot_powerup.xpm";
	data->exit_path = "sprites/Other/Portal/portal.xpm";
	load_player_side_images(data);
	load_enimies_images(data);
	data->wall_img = mlx_xpm_file_to_image(data->mlx, data->wall_path, &w, &h);
	data->coin_img = mlx_xpm_file_to_image(data->mlx, data->coin_path, &w, &h);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, data->exit_path, &w, &h);
	if (!data->wall_img || !data->coin_img || !data->exit_img
		||!data->bonus.img_closed || !data->bonus.img_full_open_down
		|| !data->bonus.img_full_open_left || !data->bonus.img_full_open_right
		|| !data->bonus.img_full_open_up || !data->bonus.img_semi_open_down
		|| !data->bonus.img_semi_open_left || !data->bonus.img_semi_open_right
		|| !data->bonus.img_semi_open_up || !data->bonus.img_enimy_down
		|| !data->bonus.img_enimy_left || !data->bonus.img_enimy_right
		|| !data->bonus.img_enimy_up)
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
	if (!init_enemies(data))
		return (0);
	return (1);
}
