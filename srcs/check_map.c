/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:44:43 by minabe            #+#    #+#             */
/*   Updated: 2023/05/02 11:57:54 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	count_map_width(char *map)
{
	size_t	i;
	size_t	j;
	size_t	width;

	i = 0;
	width = 0;
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i+j] != '\n')
			j++;
		if (width == 0)
			width = j;
		else if (width != j)
		{
			free(map);
			ft_error("Invalid map");
		}
		i += j + 1;
	}
	return (width);
}

size_t	count_map_height(char *map)
{
	size_t	i;
	size_t	height;

	i = 0;
	height = 1;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			height++;
		i++;
	}
	return (height);
}

bool	check_obj(char *map)
{
	size_t	i;
	size_t	start;
	size_t	item;
	size_t	goal;

	i = 0;
	start = 0;
	item = 0;
	goal = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'P')
			start++;
		else if (map[i] == 'E')
			goal++;
		else if (map[i] == 'C')
			item++;
		else if (map[i] != '1' && map[i] != '0' && map[i] != '\n')
			return (false);
		i++;
	}
	if (start != 1 || goal != 1 || item == 0)
		return (false);
	return (true);
}

bool	check_map(char *map)
{
	if (count_map_width(map) == count_map_height(map))
		return (false);
	if (check_obj(map) == false)
		return (false);
	return (true);
}
