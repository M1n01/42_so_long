/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/05/10 17:31:58 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	end_game(t_game *game)
{
	ft_printf("Exit game\n");
	mlx_destroy_window(game->ptr, game->win_ptr);
	destroy_objs(game);
	ft_free(game->map_info->map);
	ft_free(game);
	exit(0);
	return (0);
}

int	deal_key(int keycode, t_game *game)
{
	if (keycode == KEY_Q || keycode == KEY_ESC)
		end_game(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		move(game, UP);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move(game, LEFT);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move(game, DOWN);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move(game, RIGHT);
	redraw_player(game);
	return (0);
}

void	make_start_window(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	width;
	size_t	height;
	char	*map;

	map = game->map_info->map;
	width = game->map_info->width;
	height = game->map_info->height;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width && map[i * width + j] != '\0')
		{
			put_obj(game, map[i * width + j], j, i);
			j++;
		}
		i++;
	}
}

t_game	*init_game(char *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("Malloc failed");
	game->ptr = mlx_init();
	if (game->ptr == NULL)
		ft_error("Mlx init failed");
	game->win_ptr = NULL;
	game->width = 640;
	game->height = 480;
	game->map_info->width = count_map_width(map) + 1;
	game->map_info->height = count_map_height(map);
	game->map_info->map = map;
	puts("map");
	game->objs = init_objs(game);
	game->turn = 0;
	return (game);
}

void	start_game(char *map)
{
	t_game	*game;

	game = init_game(map);
	game->win_ptr = mlx_new_window(game->ptr, \
		game->width, game->height, "so_long");
	if (game->win_ptr == NULL)
		ft_error("Mlx window init failed");
	make_start_window(game);
	mlx_key_hook(game->win_ptr, deal_key, game);
	mlx_hook(game->win_ptr, 33, 1L << 17, end_game, game);
	mlx_loop(game->ptr);
	return ;
}
