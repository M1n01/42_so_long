/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/04/28 18:26:04 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/libft.h"
# include "../include/so_long.h"

void	draw_map(t_map map)
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

void	mlx()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "test");
	draw_map(map);
	mlx_loop(mlx);
	// 最初のうちはCtrl+Cで終了
	// のちに終了するプログラムを書く
	return (0);
}
