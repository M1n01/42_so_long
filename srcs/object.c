/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:51:53 by minabe            #+#    #+#             */
/*   Updated: 2023/05/08 15:26:44 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

t_obj	*init_obj(char *relative_path)
{
	t_obj *obj;

	obj = malloc(sizeof(t_obj));
	if (!obj)
		ft_error("Malloc failed");
	obj->img = NULL;
	obj->width = NULL;
	obj->height = NULL;
	obj->path = relative_path;
	return (obj);
}

void	put_obj(t_mlx *mlx, t_obj *obj, int x, int y)
{
	obj->img = mlx_xpm_file_to_image(mlx->mlx_ptr, obj->path,\
		obj->width, obj->height);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, obj->img, x, y);
}
