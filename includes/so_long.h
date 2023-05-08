/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:26 by minabe            #+#    #+#             */
/*   Updated: 2023/05/08 18:27:17 by minabe           ###   ########.fr       */
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

typedef struct s_obj
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
}	t_obj;

typedef struct s_game
{
	void	*ptr;
	void	*win_ptr;
	int		width;
	int		height;
	char	*map;
	t_obj	objs;
}	t_game;

size_t	count_map_width(char *map);
size_t	count_map_height(char *map);
bool	check_map(char *map);
char	*get_map(char *file);

int	win_close(int keycode, t_game *mlx);

t_obj	*init_obj(char *relative_path);
void	put_obj(t_game *mlx, t_obj *obj, int x, int y);

void	newgame(char *map);

#endif
