/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:44:43 by minabe            #+#    #+#             */
/*   Updated: 2023/05/10 19:35:52 by minabe           ###   ########.fr       */
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
		if (map[i] == '\n')
			i++;
		j = 0;
		while (map[i+j] != '\n' && map[i+j] != '\0')
			j++;
		printf("j: %zu\n", j);
		if (width == 0)
			width = j;
		else if (width != j && j != 0)
			ft_error("Invalid width map");
		i += j;
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
	{
		printf("not rectangle\n");
		return (false);
	}
	return (check_obj(map));
}

char	*get_map(char *file)
{
	int		fd;
	char	*map;
	char	*tmp;
	char	*buf;
	ssize_t	read_size;

	map = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open file");
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		ft_error("malloc failed");
	read_size = 1;
	while (read_size != 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			ft_error("Failed to read file");
		tmp = ft_strjoin(map, buf);
		ft_free(map);
		map = tmp;
	}
	ft_free(buf);
	close(fd);
	return (map);
}
