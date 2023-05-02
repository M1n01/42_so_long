/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:26 by minabe            #+#    #+#             */
/*   Updated: 2023/05/01 23:20:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
// # include "../minilibx-linux/mlx.h"
// # include "../minilibx-linux/mlx_int.h"
#include "debug.h"

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}	t_map;

void	mlx();
bool	check_map(char *map);
size_t	count_map_width(char *map);

#endif
