/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:29:56 by minabe            #+#    #+#             */
/*   Updated: 2023/05/15 00:29:51 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	isValidMove(t_map *map, size_t x, size_t y, char c)
{
	if (x >= 0 && x < map->width && y >= 0 && y < map->height)
	{
		if (map->map[y * map->width + x] != '1')
		{
			if (c != 'E' && map->map[y * map->width + x] == 'E')
				return (false);
			else
				return (true);
		}
	}
	return (false);
}

void	solveMaze(t_map *map, size_t x, size_t y, bool *flag, char c)
{
	int	cmd;
	size_t	ni;
	size_t	nj;

	if (!isValidMove(map, x, y, c))
		return ;
	if (map->map[y * map->width + x] == 'P')
	{
		*flag = 1;
		return ;
	}
	c = map->map[y * map->width + x];
	map->map[y * map->width + x] = 'x';
	cmd = -1;
	while (++cmd < 4)
	{
		if (cmd == UP || cmd == DOWN)
		{
			ni = x;
			if (cmd == UP)
				nj = y - 1;
			if (cmd == DOWN)
				nj = y + 1;
		}
		else if (cmd == LEFT || cmd == RIGHT)
		{
			if (cmd == LEFT)
				ni = x - 1;
			if (cmd == RIGHT)
				ni = x + 1;
			nj = y;
		}
		if (0 <= ni && ni < map->width && 0 <= nj && nj < map->height)
		{
			if (map->map[nj * map->width + ni] != '1')
			{
				if (map->map[nj * map->width + ni] != 'x')
					solveMaze(map, ni, nj, flag, c);
			}
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
