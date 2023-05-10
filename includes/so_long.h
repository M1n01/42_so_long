/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:26 by minabe            #+#    #+#             */
/*   Updated: 2023/05/10 10:49:16 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
#include <stdio.h>

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

enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct s_objs
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
}	t_objs;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	void	*ptr;
	void	*win_ptr;
	int		width;
	int		height;
	char	*map;
	t_objs	objs;
	t_player	player;
}	t_game;

size_t	count_map_width(char *map);
size_t	count_map_height(char *map);
bool	check_map(char *map);
char	*get_map(char *file);

int	win_close(int keycode, t_game *mlx);

t_objs	init_objs(t_game *game);
void	destroy_objs(t_game *game);

void	move(t_game *game, int dir);

void	newgame(char *map);

#endif
