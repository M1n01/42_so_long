/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:26 by minabe            #+#    #+#             */
/*   Updated: 2023/05/07 23:26:31 by minabe           ###   ########.fr       */
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

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

size_t	count_map_width(char *map);
size_t	count_map_height(char *map);
bool	check_map(char *map);
char	*get_map(char *file);

int	win_close(int keycode, t_mlx *mlx);

void	mlx(char *map);

#endif
