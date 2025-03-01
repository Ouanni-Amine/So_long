/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:10:01 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/17 10:03:34 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_positions(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			else if (data->map[y][x] == 'E')
			{
				data->exit_x = x;
				data->exit_y = y;
			}
			else if (data->map[y][x] == 'C')
				data->coins++;
			x++;
		}
		y++;
	}
}

int	map_demensions(t_game *data, char *map_name)
{
	char	*line;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd ("Error\nOpening map file is failed", 2);
		return (0);
	}
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd ("ERROR\nInvalid map", 2);
		close(fd);
		return (0);
	}
	data->map_w = (ft_strlen(line) - 1);
	while (line)
	{
		data->map_h++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (1);
}

int	line_reader(int fd, t_game *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(data->map);
		data->map = NULL;
		return (0);
	}
	while (line)
	{
		data->map[i] = ft_strdup(line);
		free(line);
		if (!data->map[i])
		{
			free_map(data->map);
			return (0);
		}
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	return (1);
}

int	read_map(t_game *data, char *map_name)
{
	int		fd;

	if (!map_demensions(data, map_name))
		return (0);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nOpening map file is failed", 2);
		return (0);
	}
	data->map = malloc(sizeof(char *) * (data->map_h + 1));
	if (!data->map)
	{
		close (fd);
		ft_putstr_fd("Error\nAllocating memeory for map is failed", 2);
		return (0);
	}
	if (!line_reader(fd, data))
	{
		close(fd);
		return (0);
	}
	close(fd);
	map_positions(data);
	return (1);
}
