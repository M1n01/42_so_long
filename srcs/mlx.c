/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/05/02 14:05:49 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

void	draw_map(char *map, t_mlx *mlx)
{
	int	i;
	int	j;
	int	width = 1000;
	int	height = 1000;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, j, 127);
			mlx_key_hook(mlx->win_ptr, deal_key, NULL);
			j++;
		}
		i++;
	}
}

void	mlx(char *map)
{
	t_mlx	*mlx;

	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height, "test");
	draw_map(map, mlx);
	mlx_loop(mlx->mlx_ptr);
	// 最初のうちはCtrl+Cで終了
	// のちに終了するプログラムを書く
	return (0);
}
