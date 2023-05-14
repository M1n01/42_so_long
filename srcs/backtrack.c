/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:29:56 by minabe            #+#    #+#             */
/*   Updated: 2023/05/14 23:22:51 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_plr(t_map *map, size_t *x, size_t *y)
{
	size_t	i;
	size_t	j;

	*x = 0;
	*y = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width && map->map[i * map->width + j] != '\0')
		{
			if (map->map[i * map->width + j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

bool	isValidMove(t_map *map, size_t x, size_t y, char c)
{
	if (x >= 0 && x < map->width && y >= 0 && y < map->height)
	{
		if (map->map[y * map->width + x] != '1')
		{
			if (c != 'E' && map->map[y * map->width + x] != 'E')
				return (true);
			else if (c == 'E' && map->map[y * map->width + x] == 'E')
				return (true);
		}
	}
	return (false);
}

void	solveMaze(t_map *map, size_t x, size_t y, bool *flag, char c)
{
	size_t ni, nj;

	if (!isValidMove(map, x, y, c))
		return ;
	if (map->map[y * map->width + x] == 'P')
	{
		// puts("Goal");
		// printf("x: %zu, y: %zu\n", x, y);
		*flag = 1;
		return ;
	}
	c = map->map[y * map->width + x];
	map->map[y * map->width + x] = 0;

	// 上に進む
	ni = x;
	nj = y - 1;
	if (nj >= 0)
	{
		if (map->map[nj * map->width + ni] != '1')
		{
			if (map->map[nj * map->width + ni] != 0)
				solveMaze(map, ni, nj, flag, c);
		}
	}

	// 下に進む
	ni = x;
	nj = y + 1;
	if (nj < map->height)
	{
		if (map->map[nj * map->width + ni] != '1')
		{
			if (map->map[nj * map->width + ni] != 0)
				solveMaze(map, ni, nj, flag, c);
		}
	}

	// 左に進む
	ni = x - 1;
	nj = y;
	if (ni >= 0)
	{
		if (map->map[nj * map->width + ni] != '1')
		{
			if (map->map[nj * map->width + ni] != 0)
				solveMaze(map, ni, nj, flag, c);
		}
	}

	// 右に進む
	ni = x + 1;
	nj = y;
	if (ni < map->width)
	{
		if (map->map[nj * map->width + ni] != '1')
		{
			if (map->map[nj * map->width + ni] != 0)
				solveMaze(map, ni, nj, flag, c);
		}
	}
	map->map[y * map->width + x] = c;
	return ;
}

bool solveItem(t_map *map)
{
	size_t	i, j;
	bool	flag;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width && map->map[i * map->width + j] != '\0')
		{
			if (map->map[i * map->width + j] == 'C' || map->map[i * map->width + j] == 'E')
			{
				flag = false;
				printf("%c\n", map->map[i * map->width + j]);
				printf("x: %zu, y: %zu\n", j, i);
				solveMaze(map, j, i, &flag, map->map[i * map->width + j]);
				if (flag == false)
				{
					puts("NG");
					return (false);
				}
				else
					puts("OK");
			}
			j++;
		}
		i++;
	}
	return (true);
}
