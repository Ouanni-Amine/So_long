/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:07:33 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/16 18:27:22 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		cleanup(&data);
		return (1);
	}
	if (!init_game(&data))
	{
		cleanup (&data);
		return (1);
	}
	mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 17, 0, handle_close, &data);
	draw(&data);
	mlx_loop(data.mlx);
	return (0);
}
