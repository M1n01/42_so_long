/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:31:39 by minabe            #+#    #+#             */
/*   Updated: 2023/03/03 18:36:53 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/libft.h"
# include "../include/so_long.h"

void	mlx()
{
	t_program	*mlx;
	mlx->mlx_pointer = init_mlx();
	mlx->window = mlx_new_window(mlx->mlx_pointer, width, height, name);
	if (mlx->window == NULL)
		exit(1);
	mlx_loop(mlx->mlx_pointer);
	mlx_hook(mlx->mlx_pointer, )
}