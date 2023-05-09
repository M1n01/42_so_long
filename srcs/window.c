/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:26:00 by minabe            #+#    #+#             */
/*   Updated: 2023/05/09 10:09:52 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	win_close(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->ptr, game->win_ptr);
		/*free関数をそうにゅうする*/
		exit(0);
	}
	return (0);
}
