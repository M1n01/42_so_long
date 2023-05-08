/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:26 by minabe            #+#    #+#             */
/*   Updated: 2023/05/08 20:06:04 by minabe           ###   ########.fr       */
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

# define ESC 65307

typedef struct s_objs
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
}	t_objs;

typedef struct s_game
{
	void	*ptr;
	void	*win_ptr;
	int		width;
	int		height;
	char	*map;
	t_objs	objs;
}	t_game;

size_t	count_map_width(char *map);
size_t	count_map_height(char *map);
bool	check_map(char *map);
char	*get_map(char *file);

int	win_close(int keycode, t_game *mlx);

t_objs	init_objs(t_game *game);
void	destroy_objs(t_game *game);

void	newgame(char *map);

#endif
