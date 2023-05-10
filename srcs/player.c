/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:23:36 by minabe            #+#    #+#             */
/*   Updated: 2023/05/10 10:50:58 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void	move(t_game *game, int dir)
{
	if (dir == UP)
		game->player.y -= 1;
	if (dir == DOWN)
		game->player.y += 1;
	if (dir == LEFT)
		game->player.x -= 1;
	if (dir == RIGHT)
		game->player.x += 1;
	printf("x: %d, y: %d\n", game->player.x, game->player.y);
}
