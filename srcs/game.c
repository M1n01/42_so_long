/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/05/11 14:47:52 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_game(char *map)
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

t_game	*init_game(char *mp)
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
	game->map_info.map = mp;
	game->map_info.width = count_map_width(mp) + 1;
	game->map_info.height = count_map_height(mp);
	game->objs = init_objs(game);
	game->player = init_plr(game);
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
	ft_free(game);
	exit(0);
	return (0);
}
