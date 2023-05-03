/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/05/03 12:31:29 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"
# include "../minilibx-linux/mlx_int.h"

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	(void)key;
	(void)param;
	return (0);
}

void	draw_map(char *map, t_mlx *mlx)
{
	int	i;
	int	j;

	(void)map;
	i = 0;
	while (i < mlx->width)
	{
		j = 0;
		while (j < mlx->height)
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

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		ft_error("Malloc failed");
	mlx->height = 1000;
	mlx->width = 1000;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height, "test");
	draw_map(map, mlx);
	mlx_loop(mlx->mlx_ptr);
	// 最初のうちはCtrl+Cで終了
	// のちに終了するプログラムを書く
	return ;
}
