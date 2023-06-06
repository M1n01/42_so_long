/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:26 by minabe            #+#    #+#             */
/*   Updated: 2023/06/06 23:16:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include "libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# define KEY_ESC 65307
# define KEY_Q 113
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define SIZE 32

enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct s_map
{
	char	*map;
	size_t	width;
	size_t	height;
}	t_map;

typedef struct s_vector
{
	size_t	x;
	size_t	y;
}	t_vector;

typedef struct s_objs
{
	void	*wall;
	void	*exit;
	void	*collectible;
	void	*floor;
}	t_objs;

typedef struct s_player
{
	void	*player_down;
	void	*player_up;
	void	*player_left;
	void	*player_right;
	int		dir;
	int		x;
	int		y;
	int		pre_x;
	int		pre_y;
}	t_player;

typedef struct s_game
{
	void		*ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_map		map_info;
	t_objs		objs;
	t_player	player;
	int			turn;
	bool		clear;
}	t_game;

size_t		count_map_width(char *map);
size_t		count_map_height(char *map);
bool		check_map(t_map *map);
char		*get_map(char *file);

t_objs		init_objs(t_game *game);
void		destroy_objs(t_game *game);
void		put_obj(t_game *game, char c, int x, int y);

t_player	init_plr(t_game *game);
void		destroy_plr(t_game *game);
void		plr_move(t_game *game, int dir);
int			check_game(t_game *game);

void		start_game(t_map *map);
int			end_game(t_game *game);

int			deal_key(int keycode, t_game *game);
int			make_start_window(t_game *game);

bool		check_reach_objs(t_map *mp);

#endif
