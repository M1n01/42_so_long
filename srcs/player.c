/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:23:36 by minabe            #+#    #+#             */
/*   Updated: 2023/05/11 14:47:47 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

t_player	init_plr(t_game *game)
{
	int			size;
	t_player	plr;

	size = SIZE;
	plr.player_down = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Pac-Man/pac_closed.xpm", &size, &size);
	if (plr.player_down == NULL)
		printf("error\n");
	plr.player_up = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Pac-Man/pac_closed.xpm", &size, &size);
	if (plr.player_up == NULL)
		printf("error\n");
	plr.player_left = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Pac-Man/pac_closed.xpm", &size, &size);
	if (plr.player_left == NULL)
		printf("error\n");
	plr.player_right = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Pac-Man/pac_closed.xpm", &size, &size);
	if (plr.player_right == NULL)
		printf("error\n");
	plr.x = -1;
	plr.y = -1;
	return (plr);
}

void	destroy_plr(t_game *game)
{
	mlx_destroy_image(game->ptr, game->player.player_down);
	mlx_destroy_image(game->ptr, game->player.player_up);
	mlx_destroy_image(game->ptr, game->player.player_left);
	mlx_destroy_image(game->ptr, game->player.player_right);
}

void	plr_move(t_game *game, int dir)
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

int	check_game(t_game *game)
{
	mlx_put_image_to_window(game->ptr, game->win_ptr, \
		game->objs.player, game->player.x * 32, game->player.y * 32);
	mlx_put_image_to_window(game->ptr, game->win_ptr, \
		game->objs.floor, game->player.pre_x * 32, game->player.pre_y * 32);
	if (game->map_info.map[game->player.y * game->map_info.width + \
		game->player.x] == 'C')
	{
		game->map_info.map[game->player.y * game->map_info.width + \
			game->player.x] = '0';
	}
	if (game->map_info.map[game->player.y * game->map_info.width + \
		game->player.x] == 'E')
	{
		game->clear = true;
		end_game(game);
	}
	return (0);
}
