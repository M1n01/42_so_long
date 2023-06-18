/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/06/18 22:36:22 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_game	*init_game(t_map *mp);

void	start_game(t_map *map)
{
	t_game	*game;

	game = init_game(map);
	game->win_ptr = mlx_new_window(game->ptr, \
		game->width, game->height, "so_long");
	if (game->win_ptr == NULL)
		ft_error("Mlx window init failed");
	mlx_loop_hook(game->ptr, make_start_window, game);
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
		ft_error("Malloc failed");
	game->ptr = mlx_init();
	if (game->ptr == NULL)
		ft_error("Mlx init failed");
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
		ft_error("Malloc failed");
	game->turn = 0;
	game->clear = false;
	return (game);
}

int	end_game(t_game *game)
{
	if (game->clear == false)
		ft_printf("Exit game\n");
	else
		ft_printf("Congrats, clear game!!\n");
	mlx_destroy_window(game->ptr, game->win_ptr);
	destroy_plr(game);
	destroy_objs(game);
	ft_free(game->map_info.map);
	ft_free(game->items);
	ft_free(game);
	exit(0);
	return (0);
}
