/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:26:00 by minabe            #+#    #+#             */
/*   Updated: 2023/05/07 23:26:19 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	win_close(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	return (0);
}
