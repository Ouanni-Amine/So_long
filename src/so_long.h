/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:53:05 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/16 14:14:13 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../GNL/get_next_line.h"
# include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_game_assets
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*wall_img;
	void	*player_img;
	void	*coin_img;
	void	*exit_img;
	int		map_h;
	int		map_w;
	int		player_y;
	int		player_x;
	int		coins;
	int		collected;
	int		exit_x;
	int		exit_y;
	int		moves;
	int		img_size;
	int		valid_path;
	char	*wall_path;
	char	*player_path;
	char	*coin_path;
	char	*exit_path;
	void	*right_side;
	void	*left_side;
	void	*down_side;
	void	*up_side;
	void	*old_img;
}	t_game;

int		read_map(t_game *data, char *map_name);
void	draw(t_game *data);
void	move_player(int key, t_game *data);
int		init_game(t_game *data);
void	free_map(char **map);
void	init_vars(t_game *data);
char	**copy_map(t_game *data);
int		flood_fill(char **map_copy, t_game *data, int y, int x);
int		map_validat(t_game *data, char *map_name);
void	cleanup(t_game *data);
int		is_map_very_big(t_game *data);

#endif