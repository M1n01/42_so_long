/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:34:14 by minabe            #+#    #+#             */
/*   Updated: 2023/05/11 16:08:41 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	check_objs(char *map);
static bool	check_wall(char *map);

bool	check_map(char *map)
{
	if (count_map_width(map) == count_map_height(map))
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

static bool	check_objs(char *map)
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

static bool	check_wall(char *map)
{
	size_t	i;
	size_t	width;

	width = count_map_width(map) + 1;
	i = 0;
	while (map[i] != '\0')
	{
		if (i < width || i > ft_strlen(map) - width)
		{
			if (map[i] != '1' && map[i] != '\n')
				return (false);
		}
		if (i % width == 0 || i % width == width - 2)
		{
			if (map[i] != '1')
				return (false);
		}
		i++;
	}
	return (true);
}

// static bool	check_player_getting_object(char *map)
// {
// 	size_t	i;
// 	size_t	width;

// 	// PからCとEに到達できるか動的計画法で判定
// 	width = count_map_width(map) + 1;
// 	i = 0;
// 	return (true);
// }