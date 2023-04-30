/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:43:24 by minabe            #+#    #+#             */
/*   Updated: 2023/04/28 18:54:10 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/so_long.h"

char	**read_map(char *file)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Failed to open file");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open file");
	map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map)
		ft_error("Failed to allocate memory");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	char	**map;
	if (argc < 2)
		ft_error("No map file");
	map = read_map(argv[1]);
	mlx();
	return (0);
}