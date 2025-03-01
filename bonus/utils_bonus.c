/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:51:04 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/16 19:58:34 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

char	**copy_map(t_game *data)
{
	char	**new_map;
	int		y;

	y = 0;
	new_map = malloc(sizeof(char *) * (data->map_h + 1));
	if (!new_map)
		return (NULL);
	while (y < data->map_h)
	{
		new_map[y] = ft_strdup(data->map[y]);
		if (!new_map[y])
		{
			free_map(new_map);
			return (NULL);
		}
		y++;
	}
	new_map[y] = NULL;
	return (new_map);
}

int	flood_fill(char **map_copy, t_game *data, int y, int x)
{
	static int	coin_count;
	static int	exit_found;

	if (x < 0 || x >= data->map_w || y < 0 || y >= data->map_h
		|| map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return (0);
	if (map_copy[y][x] == 'C')
		coin_count++;
	if (map_copy[y][x] == 'E')
		exit_found = 1;
	map_copy[y][x] = 'V';
	flood_fill(map_copy, data, y, x + 1);
	flood_fill(map_copy, data, y, x - 1);
	flood_fill(map_copy, data, y + 1, x);
	flood_fill(map_copy, data, y - 1, x);
	return (coin_count == data->coins && exit_found == 1);
}

void	cleanup(t_game *data)
{
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->map)
		free_map(data->map);
	if (data->enemies)
		free(data->enemies);
}

int	is_map_very_big(t_game *data)
{
	if (data->map_h > 44 || data->map_w > 80)
	{
		ft_putstr_fd("ERROR\nmap is exceeding hight or width limites", 2);
		return (0);
	}
	return (1);
}
