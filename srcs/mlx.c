/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/05/08 18:37:10 by minabe           ###   ########.fr       */
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
	game->win_ptr = mlx_new_window(game->ptr, game->width, game->height, "Game");
	game->width = 1920;
	game->height = 1080;
	game->map = map;
	// game->objs = NULL;
	return (game);
}

void	newgame(char *map)
{
	t_game	*game;
	// t_data	img;
	// t_obj	*jiki;
	// t_obj	*wall;
	// t_obj	*coin;
	// t_obj	*exit;

	(void)map;
	game = init_game(map);
	// jiki = init_obj("./img/sprites/Pac-Man/pac_closed.xpm");
	// wall = init_obj("./img/sprites/Walls/wall.xpm");
	// exit = init_obj("./img/sprites/Portal/portal.xpm");
	// coin = init_obj("./img/sprites/Pacdots/pacdot_powerup.xpm");
	// put_obj(game, jiki, 100, 100);
	// put_obj(mlx, wall, 0, 0);
	// put_obj(mlx, exit, 20, 20);
	// put_obj(mlx, coin, 30, 30);
	mlx_hook(game->win_ptr, 2, 1L<<0, win_close, game);
	mlx_loop(game->ptr);
	// ft_free(jiki);
	// ft_free(wall);
	// ft_free(exit);
	// ft_free(coin);
	ft_free(game);
	return ;
}
