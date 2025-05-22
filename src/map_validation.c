/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:26:12 by aouanni           #+#    #+#             */
/*   Updated: 2025/05/22 18:54:30 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(t_game *data)
{
	int		i;
	size_t	len;

	if (data->map_h <= 1)
		return (0);
	len = ft_strlen(data->map[0]);
	i = 1;
	while (i < data->map_h - 1)
	{
		if (ft_strlen(data->map[i]) != len)
			return (0);
		i++;
	}
	if ((ft_strlen(data->map[i]) != len - 1)
		&& (!ft_strchr(data->map[i], '\n')))
		return (0);
	if ((ft_strlen(data->map[i]) != len) && (ft_strchr(data->map[i], '\n')))
		return (0);
	return (1);
}

int	is_surrounded_by_walls(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if ((x == 0 || x == (data->map_w - 1) || y == 0
					|| y == (data->map_h - 1)) && data->map[y][x] != '1')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_chars(t_game *data)
{
	int	x;
	int	y;
	int	p_count;
	int	e_count;

	y = 0;
	p_count = 0;
	e_count = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (data->map[y][x] == 'P')
				p_count++;
			else if (data->map[y][x] == 'E')
				e_count++;
			else if (data->map[y][x] != '1' && data->map[y][x] != '0'
				&& data->map[y][x] != 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (p_count == 1 && e_count == 1 && data->coins > 0);
}

int	check_path(t_game *data)
{
	char	**map_copy;
	int		res;

	map_copy = copy_map(data);
	if (!map_copy)
		return (0);
	res = flood_fill(map_copy, data, data->player_y, data->player_x);
	free_map(map_copy);
	return (res);
}

int	map_validat(t_game *data, char *map_name)
{
	if (!read_map(data, map_name))
		return (0);
	if (!is_rectangle(data))
	{
		ft_putstr_fd("Error\nThe map should be rectangle", 2);
		return (0);
	}
	if (!is_surrounded_by_walls(data))
	{
		ft_putstr_fd("Error\nThe map must be surrounded by walls", 2);
		return (0);
	}
	if (!check_chars(data))
	{
		ft_putstr_fd("Error\nInvalide charcter founded in the map", 2);
		return (0);
	}
	if (!is_map_very_big(data))
		return (0);
	if (!check_path(data))
	{
		ft_putstr_fd ("Error\nInvalid map path", 2);
		return (0);
	}
	return (1);
}
