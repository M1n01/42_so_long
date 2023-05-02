/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:43:24 by minabe            #+#    #+#             */
/*   Updated: 2023/05/02 00:29:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_map(char *file)
{
	int		fd;
	char	*map;
	char	*new;
	char	*buf;
	ssize_t	read_size;

	map = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open file");
	read_size = 1;
	while (read_size > 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			ft_error("malloc failed");
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			ft_error("Failed to read file");
		buf[read_size] = '\0';
		// malloc error起きてる？？
		new = ft_strjoin(map, buf);
		free(buf);
		free(map);
		map = new;
	}
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	char	*map;

	if (argc < 2)
		ft_error("No map file");
	puts("get map");
	map = get_map(argv[1]);
	if (check_map(map) == false)
		ft_error("Invalid map");
	printf("[map]\n%s\n", map);
	// mlx();
	ft_free(map);
	return (0);
}
