/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:51:53 by minabe            #+#    #+#             */
/*   Updated: 2023/05/08 12:53:20 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void	init_obj(t_obj *obj)
{
	obj->img = NULL;
	obj->width = 0;
	obj->height = 0;
	obj->relative_path = NULL;
}
