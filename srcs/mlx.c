/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/05/09 10:05:45 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	deal_key(int key, void *param)
{
	// ft_putchar('X');
	printf("%d\n", key);
	(void)param;
	return (0);
}

// map
void	draw_map(char *map, t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	width;
	size_t	height;

	width = count_map_width(map);
	height = count_map_height(map);
	printf("width: %zu\n", width);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j <= width || map[i * width + j] != '\0')
		{
			printf("%zd\n", i * width + j);
			printf("%c\n", map[i * width + j]);
			// if (map[i * width + j] == '1')
			// {
			// 	puts("draw wall");
			// 	printf("i: %zu, j: %zu\n", i, j);
			// 	mlx_put_image_to_window(game->ptr, game->win_ptr, game->objs.wall, 32 * j, 32 * i);
			// }
			// else if (map[i * width + j] == 'P')
			// {
			// 	puts("draw player");
			// 	printf("i: %zu, j: %zu\n", i, j);
			// 	mlx_put_image_to_window(game->ptr, game->win_ptr, game->objs.player, 32 * j, 32 * i);
			// 	puts("draw player end");
			// }
			// else if (map[i * width + j] == 'C')
			// {
			// 	puts("draw collectible");
			// 	printf("i: %zu, j: %zu\n", i, j);
			// 	mlx_put_image_to_window(game->ptr, game->win_ptr, game->objs.collectible, 32 * j, 32 * i);
			// }
			// else if (map[i * width + j] == 'E')
			// {
			// 	puts("draw exit");
			// 	printf("i: %zu, j: %zu\n", i, j);
			// 	mlx_put_image_to_window(game->ptr, game->win_ptr, game->objs.exit, 32 * j, 32 * i);
			// }
			j++;
		}
		i++;
	}
	(void)map;
	(void)game;
	// mlx_put_image_to_window(game->ptr, game->win_ptr, game->objs.exit, 6, 10);
	// mlx_key_hook(game->win_ptr, deal_key, NULL);
}

t_game	*init_game(char *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("Malloc failed");
	game->ptr = mlx_init();
	game->win_ptr = NULL;
	game->width = 1440;
	game->height = 900;
	game->map = map;
	game->objs = init_objs(game);
	return (game);
}

void	newgame(char *map)
{
	t_game	*game;

	(void)map;
	game = init_game(map);
	game->win_ptr = mlx_new_window(game->ptr, game->width, game->height, "Game");
	draw_map(map, game);
	mlx_hook(game->win_ptr, 2, 1L<<0, win_close, game);
	mlx_loop(game->ptr);
	destroy_objs(game);
	ft_free(game);
	return ;
}
