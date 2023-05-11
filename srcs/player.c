/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:23:36 by minabe            #+#    #+#             */
/*   Updated: 2023/05/11 11:38:22 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void	move(t_game *game, int dir)
{
	int		tmp_x;
	int		tmp_y;
	char	*map;

	map = game->map_info.map;
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
	if (map[tmp_y * game->map_info.width + tmp_x] != '1')
	{
		game->player.pre_x = game->player.x;
		game->player.pre_y = game->player.y;
		game->player.x = tmp_x;
		game->player.y = tmp_y;
		game->turn++;
		ft_printf("turn: %d\n", (int)game->turn);
	}
}

int	redraw_player(t_game *game)
{
	mlx_put_image_to_window(game->ptr, game->win_ptr, \
		game->objs.player, game->player.x * 32, game->player.y * 32);
	mlx_put_image_to_window(game->ptr, game->win_ptr, \
		game->objs.floor, game->player.pre_x * 32, game->player.pre_y * 32);
	return (0);
}
