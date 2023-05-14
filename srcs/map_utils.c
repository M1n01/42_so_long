/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:34:14 by minabe            #+#    #+#             */
/*   Updated: 2023/05/12 22:09:24 by minabe           ###   ########.fr       */
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

// bool	check_goal(t_map *map, t_vector pos, t_vector pl)
// {
// 	if (pos.x == pl.x && pos.y == pl.y)
// 		return (true);
// 	if (pos.x >= 0 && pos.x < pl.x && pos.y >= 0 && pos.y < pl.y && map->map[pos.y * map->width + pos.x] != 1)
// 	{
// 		;
// 	}
// 	return (false);
// }

// bool	backtrack(t_map *map)
// {
// 	size_t	i;
// 	size_t	j;
// 	t_vector	plr;
// 	t_vector	pos;

// 	find_plr(map, &plr.x, &plr.y);
// 	i = 0;
// 	while (i < map->height)
// 	{
// 		j = 0;
// 		while (j < map->width && map->map[i * map->width + j] != '\0')
// 		{
// 			if (map->map[i * map->width + j] == 'C' || \
// 				map->map[i * map->width + j] == 'E')
// 			{
// 				pos.x = j;
// 				pos.y = i;
// 				if (check_goal(map, pos, plr) == false)
// 					return (false);
// 				if (check_goal(map, pos, plr) == true)
// 				{
// 					printf("%c\n", map->map[i * map->width + j]);
// 					puts("true!!");
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (true);
// }
