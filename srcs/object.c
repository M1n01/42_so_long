/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:51:53 by minabe            #+#    #+#             */
/*   Updated: 2023/06/14 14:32:30 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_objs	init_objs(t_game *game)
{
	t_objs	objs;
	int		size;

	size = SIZE;
	objs.wall = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Other/wall.xpm", &size, &size);
	if (objs.wall == NULL)
		printf("error\n");
	objs.collectible = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Other/item.xpm", &size, &size);
	if (objs.collectible == NULL)
		printf("error\n");
	objs.exit = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Other/grave.xpm", &size, &size);
	if (objs.exit == NULL)
		printf("error\n");
	objs.floor = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Ghost/black.xpm", &size, &size);
	if (objs.floor == NULL)
		printf("error\n");
	return (objs);
}

void	destroy_objs(t_game *game)
{
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
	if (c == 'P' && game->player.x == -1 && game->player.y == -1)
	{
		game->player.x = x;
		game->player.y = y;
	}
	check_game(game);
}
