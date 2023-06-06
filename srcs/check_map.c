/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:34:14 by minabe            #+#    #+#             */
/*   Updated: 2023/06/06 23:01:40 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	check_objs(t_map *map);
static bool	check_wall(t_map *map);

bool	check_map(t_map *map)
{
	if (map->height == map->width)
	{
		ft_printf("not rectangle\n");
		return (false);
	}
	if (!check_objs(map))
	{
		ft_printf("obj error\n");
		return (false);
	}
	if (!check_wall(map))
	{
		ft_printf("wall error\n");
		return (false);
	}
	// if (!check_reach_objs(map))
	// {
	// 	ft_printf("not reach object\n");
	// 	return (false);
	// }
	return (true);
}

static bool	check_objs(t_map *map)
{
	size_t	i;
	size_t	start;
	size_t	item;
	size_t	goal;

	i = 0;
	start = 0;
	item = 0;
	goal = 0;
	while (map->map[i] != '\0')
	{
		if (map->map[i] == 'P')
			start++;
		else if (map->map[i] == 'E')
			goal++;
		else if (map->map[i] == 'C')
			item++;
		else if (map->map[i] != '1' && map->map[i] != '0' \
				&& map->map[i] != '\n')
			return (false);
		i++;
	}
	if (start != 1 || goal != 1 || item == 0)
		return (false);
	return (true);
}

static bool	check_wall(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->map[i] != '\0')
	{
		if (i < map->width || i > ft_strlen(map->map) - map->width)
		{
			if (map->map[i] != '1' && map->map[i] != '\n')
				return (false);
		}
		if (i % map->width == 0 || i % map->width == map->width - 2)
		{
			if (map->map[i] != '1')
				return (false);
		}
		i++;
	}
	return (true);
}