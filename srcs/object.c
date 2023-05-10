/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:51:53 by minabe            #+#    #+#             */
/*   Updated: 2023/05/10 13:39:31 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

t_objs	init_objs(t_game *game)
{
	t_objs objs;
	int		size;

	size = 32;
	objs.player = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Pac-Man/pac_closed.xpm", &size, &size);
	objs.wall = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Other/Walls/wall.xpm", &size, &size);
	objs.collectible = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Other/Pacdots/pacdot_powerup.xpm", &size, &size);
	objs.exit = mlx_xpm_file_to_image(game->ptr, \
		"./img/sprites/Other/Portal/portal.xpm", &size, &size);
	return (objs);
}

void	destroy_objs(t_game *game)
{
	mlx_destroy_image(game->ptr, game->objs.player);
	mlx_destroy_image(game->ptr, game->objs.wall);
	mlx_destroy_image(game->ptr, game->objs.collectible);
	mlx_destroy_image(game->ptr, game->objs.exit);
	// ft_free(game->objs.player);
	// ft_free(game->objs.wall);
	// ft_free(game->objs.exit);
	// ft_free(game->objs.collectible);
}
