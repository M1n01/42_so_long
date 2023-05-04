/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:44:43 by minabe            #+#    #+#             */
/*   Updated: 2023/05/04 17:37:59 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

static size_t	count_map_width(char *map)
{
	size_t	i;
	size_t	j;
	size_t	width;

	i = 0;
	width = 0;
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i+j] != '\n' && map[i+j] != '\0')
			j++;
		if (width == 0)
			width = j;
		else if (width != j)
		{
			free(map);
			ft_error("Invalid width map");
		}
		i += j + 1;
	}
	return (width);
}

static size_t	count_map_height(char *map)
{
	size_t	i;
	size_t	height;

	i = 0;
	height = 1;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			if (map[i + 1] == '\0')
			{
				ft_free(map);
				ft_error("Invalid height map");
			}
			height++;
		}
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
	return (check_obj(map));
}

char	*my_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		ft_error("malloc failed");
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2 + 1);
	// ft_free(s1);
	ft_free(s2);
	return (str);
}

char	*get_map(char *file)
{
	int		fd;
	char	*map;
	char	*buf;
	// char	*new;
	ssize_t	read_size;

	map = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open file");
	read_size = 1;
	puts("read_size");
	while (read_size > 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // malloc
		if (buf == NULL)
			ft_error("malloc failed");
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			ft_error("Failed to read file");
		buf[read_size] = '\0';
		printf("loop\n");
		if (map == NULL)
		{
			map = ft_strdup(buf); // malloc
			ft_free(buf); // free
		}
		else
			map = my_strjoin(map, buf); // malloc
	}
	close(fd);
	return (map);
}
