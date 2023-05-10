/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:23:36 by minabe            #+#    #+#             */
/*   Updated: 2023/05/10 13:48:04 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void	move(t_game *game, int dir)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = game->player.x;
	tmp_y = game->player.y;
	if (dir == UP)
		tmp_y -= 1;
	if (dir == DOWN)
		tmp_y += 1;
	if (dir == LEFT)
		tmp_x -= 1;
	if (dir == RIGHT)
		tmp_x += 1;
	if (game->map[tmp_y * count_map_width(game->map) + tmp_x] != '1')
	{
		game->player.x = tmp_x;
		game->player.y = tmp_y;
		game->redraw = 1;
		game->turn++;
		printf("turn: %ld\n", game->turn);
	}
	printf("x: %d, y: %d\n", game->player.x, game->player.y);
}

void	redraw_player(t_game *game)
{
	// t_player	player;

	// player = game->player;
	mlx_destroy_image(game->ptr, game->objs.player);
	mlx_put_image_to_window(game->ptr, game->win_ptr, game->objs.player, game->player.x * 32, game->player.y * 32);
}
