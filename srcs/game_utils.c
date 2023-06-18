/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:15:08 by minabe            #+#    #+#             */
/*   Updated: 2023/06/18 19:54:05 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	make_start_window(t_game *game)
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

int	deal_key(int keycode, t_game *game)
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
