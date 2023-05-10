/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/05/10 14:16:14 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void	free_game(t_game *game)
{
	mlx_destroy_window(game->ptr, game->win_ptr);
	destroy_objs(game);
	ft_free(game->map);
	ft_free(game);
	exit(0);
}

void	check_game(t_game *game)
{
	redraw_player(game);
}

int	deal_key(int keycode, t_game *game)
{
	if (keycode == KEY_Q || keycode == KEY_ESC)
	{
		ft_printf("Exit game\n");
		free_game(game);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		move(game, UP);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move(game, LEFT);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move(game, DOWN);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move(game, RIGHT);
	// if (game->redraw == 1)
	// {
		check_game(game);
		// game->redraw = 0;
	// }
	return (0);
}

void	put_objs(char *map, t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	width;
	size_t	height;

	width = count_map_width(map) + 1;
	height = count_map_height(map);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width && map[i * width + j] != '\0')
		{
			if (map[i * width + j] == '1')
				mlx_put_image_to_window(game->ptr, game->win_ptr, game->objs.wall, 32 * j, 32 * i);
			else if (map[i * width + j] == 'P')
			{
				mlx_put_image_to_window(game->ptr, game->win_ptr, game->objs.player, 32 * j, 32 * i);
				game->player.x = j;
				game->player.y = i;
			}
			else if (map[i * width + j] == 'C')
				mlx_put_image_to_window(game->ptr, game->win_ptr, game->objs.collectible, 32 * j, 32 * i);
			else if (map[i * width + j] == 'E')
				mlx_put_image_to_window(game->ptr, game->win_ptr, game->objs.exit, 32 * j, 32 * i);
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
	game->win_ptr = NULL;
	game->width = 640;
	game->height = 480;
	game->map = map;
	game->objs = init_objs(game);
	game->redraw = false;
	game->turn = 0;
	return (game);
}

void	newgame(char *map)
{
	t_game	*game;

	(void)map;
	game = init_game(map);
	game->win_ptr = mlx_new_window(game->ptr, game->width, game->height, "Game");
	put_objs(map, game);
	mlx_key_hook(game->win_ptr, deal_key, game);
	// mlx_hook(game->win_ptr, 33, 1L << 17, free_game, game);
	mlx_loop(game->ptr);
	destroy_objs(game);
	ft_free(game);
	return ;
}
