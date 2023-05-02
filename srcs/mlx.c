/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/05/02 12:53:17 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void	draw_map(char *map, t_mlx *mlx)
{
	int	i;
	int	j;
	int	width = 100;
	int	height = 100;

	i = 0;
	while (i < map.width)
	{
		j = 0;
		while (j < map.height)
		{
			mlx_pixel_put(mlx, mlx_win, i, j, 127);
			j++;
		}
		i++;
	}
}

void	mlx(char *map)
{
	t_mlx	*mlx;

	mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "test");
	draw_map(map, mlx);
	mlx_loop(mlx->mlx);
	// 最初のうちはCtrl+Cで終了
	// のちに終了するプログラムを書く
	return (0);
}
