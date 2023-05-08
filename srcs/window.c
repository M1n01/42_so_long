/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:26:00 by minabe            #+#    #+#             */
/*   Updated: 2023/05/08 18:33:15 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	win_close(int keycode, t_game *game)
{
	if (keycode == ESC)
		mlx_destroy_window(game->ptr, game->win_ptr);
	return (0);
}
