/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/05/08 01:22:39 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	deal_key(int key, void *param)
{
	// ft_putchar('X');
	printf("%d\n", key);
	(void)param;
	return (0);
}

void	draw_obj(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1)
	{
		j = 0;
		while (j < 1)
		{
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

// map
void	draw_map(char *map, t_mlx *mlx)
{
	size_t	i;
	size_t	j;
	size_t	width;
	size_t	height;

	width = count_map_width(map);
	height = count_map_height(map);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i * width + j] == '1')
			{
				draw_obj(mlx, j, i, 0xFFFFFF);
				puts("wall");
			}
			else if (map[i * width + j] == '0')
			{
				draw_obj(mlx, j, i, 0x000000);
				puts("wall");
			}
			else if (map[i * width + j] == 'P')
			{
				draw_obj(mlx, j, i, 0xFF0000);
				puts("wall");
			}
			else if (map[i * width + j] == 'C')
			{
				draw_obj(mlx, j, i, 0x00FF00);
				puts("wall");
			}
			else if (map[i * width + j] == 'E')
			{
				draw_obj(mlx, j, i, 0x0000FF);
				puts("wall");
			}
			mlx_key_hook(mlx->win_ptr, deal_key, NULL);
			j++;
		}
		i++;
	}
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx(char *map)
{
	t_mlx	*mlx;
	// t_data	img;
	void	*img;
	int		width;
	int		height;
	char	*relative_path = "./img/kirby.png";

	(void)map;
	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		ft_error("Malloc failed");
	mlx->height = 1920;
	mlx->width = 1080;
	mlx->mlx_ptr = mlx_init();
	img = mlx_xpm_file_to_image(mlx->mlx_ptr, relative_path, &width, &height);
	(void)img;
	// mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height, "test");
	// draw_map(map, mlx);
	// img.img = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// ft_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 1L<<0, win_close, mlx);
	mlx_loop(mlx->mlx_ptr);
	free(mlx);
	return ;
}
