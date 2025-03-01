/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:53:05 by aouanni           #+#    #+#             */
/*   Updated: 2025/01/16 17:56:36 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../GNL/get_next_line.h"
# include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_enimy
{
	int	x;
	int	y;
	int	direction;
}	t_enimy;

typedef struct s_bonus
{
	int		animation_state;
	int		frame_count;
	int		direction;
	void	*img_closed;
	void	*img_semi_open_left;
	void	*img_full_open_left;
	void	*img_semi_open_right;
	void	*img_full_open_right;
	void	*img_semi_open_up;
	void	*img_full_open_up;
	void	*img_semi_open_down;
	void	*img_full_open_down;
	void	*img_enimy_left;
	void	*img_enimy_right;
	void	*img_enimy_down;
	void	*img_enimy_up;
	int		enimy_frame_count;
}	t_bonus;

typedef struct s_game_assets
{
	void	*mlx;
	void	*win;
	t_bonus	bonus;
	t_enimy	*enemies;
	void	*enimie_img;
	char	**map;
	void	*wall_img;
	void	*player_img;
	void	*coin_img;
	void	*exit_img;
	int		map_h;
	int		map_w;
	int		enemy_count;
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
	char	*coin_path;
	char	*exit_path;
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
void	put_image(t_game *data, void *img, int x, int y);
void	draw_player_bonus(t_game *data);
int		init_enemies(t_game *data);
void	update_enimies(t_game *data);
int		is_valid_move(t_game *data, int new_x, int new_y);
void	draw_enemies_bonus(t_game *data);
int		is_map_very_big(t_game *data);
void	is_collision(t_game *data);

#endif