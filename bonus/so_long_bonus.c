/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:07:33 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/16 18:29:23 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_close(void *param)
{
	t_game	*data;

	data = (t_game *) param;
	cleanup(data);
	exit(0);
	return (0);
}

int	handle_key(int key, void *param)
{
	t_game	*data;

	data = (t_game *) param;
	if (key == 53)
	{
		cleanup (data);
		exit (0);
	}
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move_player (key, data);
	return (0);
}

int	loop_hook(void *param)
{
	t_game	*data;
	int		frames_per_animation;
	int		frames_per_animation_e;

	data = (t_game *) param;
	frames_per_animation = 1800;
	frames_per_animation_e = 3000;
	data->bonus.frame_count++;
	data->bonus.enimy_frame_count++;
	if (data->bonus.frame_count >= frames_per_animation)
	{
		data->bonus.frame_count = 0;
		data->bonus.animation_state = (data->bonus.animation_state + 1) % 3;
		draw(data);
	}
	if (data->bonus.enimy_frame_count >= frames_per_animation_e)
	{
		data->bonus.enimy_frame_count = 0;
		update_enimies(data);
		draw(data);
	}
	return (0);
}

int	extension_validation(int c, char *v)
{
	int	len;

	if (c != 2)
	{
		ft_putstr_fd("Error\nThe argument number must be just 2", 2);
		return (0);
	}
	len = ft_strlen(v);
	if (ft_strncmp(v + (len - 4), ".ber", 5))
	{
		ft_putstr_fd("Error\nInvalide map extenstion", 2);
		return (0);
	}
	return (1);
}

int	main(int c, char **v)
{
	t_game	data;

	if (!extension_validation(c, v[1]))
		return (1);
	init_vars(&data);
	if (!map_validat(&data, v[1]))
	{
		cleanup (&data);
		return (1);
	}
	if (!init_game(&data))
	{
		cleanup (&data);
		return (1);
	}
	mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 17, 0, handle_close, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
