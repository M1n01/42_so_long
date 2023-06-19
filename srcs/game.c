/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/06/19 14:45:49 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_game	*init_game(t_map *mp);
static int		print_window(t_game *game);
static int		deal_key(int keycode, t_game *game);

void	start_game(t_map *map)
{
	t_game	*game;

	game = init_game(map);
	game->win_ptr = mlx_new_window(game->ptr, \
		game->width, game->height, "so_long");
	if (game->win_ptr == NULL)
		ft_error("Mlx window init failed");
	mlx_loop_hook(game->ptr, print_window, game);
	mlx_key_hook(game->win_ptr, deal_key, game);
	mlx_hook(game->win_ptr, 33, 1L << 17, end_game, game);
	mlx_loop(game->ptr);
	return ;
}

static t_game	*init_game(t_map *mp)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("Malloc failed.");
	game->ptr = mlx_init();
	if (game->ptr == NULL)
		ft_error("Mlx init failed.");
	game->win_ptr = NULL;
	game->width = (mp->width - 1) * SIZE;
	game->height = mp->height * SIZE;
	game->map_info.map = mp->map;
	game->map_info.width = mp->width;
	game->map_info.height = mp->height;
	game->map_info.items = mp->items;
	game->objs = init_objs(game);
	game->player = init_plr(game);
	game->count = 0;
	game->items = malloc(sizeof(t_vector) * mp->items);
	if (game->items == NULL)
		ft_error("Malloc failed.");
	game->turn = 0;
	game->clear = false;
	return (game);
}

static int	print_window(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	width;
	size_t	height;
	char	*map;

	map = game->map_info.map;
	width = game->map_info.width;
	height = game->map_info.height;
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
	check_game(game);
	return (0);
}

static int	deal_key(int keycode, t_game *game)
{
	if (keycode == KEY_Q || keycode == KEY_ESC)
		end_game(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		plr_move(game, UP);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		plr_move(game, LEFT);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		plr_move(game, DOWN);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		plr_move(game, RIGHT);
	check_game(game);
	return (0);
}

int	end_game(t_game *game)
{
	if (game->clear == false)
		ft_printf("Exit game.\n");
	else
		ft_printf("Congrats!! Game Clear!!\n");
	mlx_destroy_window(game->ptr, game->win_ptr);
	destroy_plr(game);
	destroy_objs(game);
	ft_free(game->map_info.map);
	ft_free(game->items);
	ft_free(game);
	exit(0);
	return (0);
}
