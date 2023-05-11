/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:51:53 by minabe            #+#    #+#             */
/*   Updated: 2023/05/11 11:36:26 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_objs	init_objs(t_game *game)
{
	t_objs	objs;
	int		size;

	size = SIZE;
	objs.player = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Pac-Man/pac_closed.xpm", &size, &size);
	if (objs.player == NULL)
		printf("error\n");
	objs.wall = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Other/Walls/wall.xpm", &size, &size);
	if (objs.wall == NULL)
		printf("error\n");
	objs.collectible = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Other/Pacdots/pacdot_powerup.xpm", &size, &size);
	if (objs.collectible == NULL)
		printf("error\n");
	objs.exit = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Other/Portal/portal.xpm", &size, &size);
	if (objs.exit == NULL)
		printf("error\n");
	objs.floor = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Pac-Man/black.xpm", &size, &size);
	if (objs.floor == NULL)
		printf("error\n");
	return (objs);
}

void	destroy_objs(t_game *game)
{
	mlx_destroy_image(game->ptr, game->objs.player);
	mlx_destroy_image(game->ptr, game->objs.wall);
	mlx_destroy_image(game->ptr, game->objs.collectible);
	mlx_destroy_image(game->ptr, game->objs.exit);
	mlx_destroy_image(game->ptr, game->objs.floor);
}

void	put_obj(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			game->objs.wall, x * SIZE, y * SIZE);
	if (c == 'C')
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			game->objs.collectible, x * SIZE, y * SIZE);
	if (c == 'E')
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			game->objs.exit, x * SIZE, y * SIZE);
	if (c == '0')
		mlx_put_image_to_window(game->ptr, game->win_ptr, \
			game->objs.floor, x * SIZE, y * SIZE);
	if (c == 'P')
	{
		// mlx_put_image_to_window(game->ptr, game->win_ptr, \
			game->objs.player, x * SIZE, y * SIZE);
		game->player.x = x;
		game->player.y = y;
	}
}
