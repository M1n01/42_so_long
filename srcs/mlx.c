/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/05/08 20:06:58 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

// int	deal_key(int key, void *param)
// {
// 	// ft_putchar('X');
// 	printf("%d\n", key);
// 	(void)param;
// 	return (0);
// }

// void	draw_obj(t_mlx *mlx, int x, int y, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < 1)
// 	{
// 		j = 0;
// 		while (j < 1)
// 		{
// 			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x + i, y + j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// // map
// void	draw_map(char *map, t_mlx *mlx)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	width;
// 	size_t	height;

// 	width = count_map_width(map);
// 	height = count_map_height(map);
// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while (j < width)
// 		{
// 			if (map[i * width + j] == '1')
// 			{
// 				draw_obj(mlx, j, i, 0xFFFFFF);
// 				puts("wall");
// 			}
// 			else if (map[i * width + j] == '0')
// 			{
// 				draw_obj(mlx, j, i, 0x000000);
// 				puts("wall");
// 			}
// 			else if (map[i * width + j] == 'P')
// 			{
// 				draw_obj(mlx, j, i, 0xFF0000);
// 				puts("wall");
// 			}
// 			else if (map[i * width + j] == 'C')
// 			{
// 				draw_obj(mlx, j, i, 0x00FF00);
// 				puts("wall");
// 			}
// 			else if (map[i * width + j] == 'E')
// 			{
// 				draw_obj(mlx, j, i, 0x0000FF);
// 				puts("wall");
// 			}
// 			mlx_key_hook(mlx->win_ptr, deal_key, NULL);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

t_game	*init_game(char *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("Malloc failed");
	game->ptr = mlx_init();
	game->win_ptr = NULL;
	game->width = 1440;
	game->height = 900;
	game->map = map;
	game->objs = init_objs(game);
	return (game);
}

void	newgame(char *map)
{
	t_game	*game;

	(void)map;
	game = init_game(map);
	game->win_ptr = mlx_new_window(game->ptr, game->width, game->height, "Game");
	mlx_put_image_to_window(game->ptr, game->win_ptr, game->objs.player, 0, 0);
	mlx_hook(game->win_ptr, 2, 1L<<0, win_close, game);
	mlx_loop(game->ptr);
	destroy_objs(game);
	ft_free(game);
	return ;
}
