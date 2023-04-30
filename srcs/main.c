/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:43:24 by minabe            #+#    #+#             */
/*   Updated: 2023/04/30 17:34:31 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*read_map(char *file)
{
	char	*map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Failed to open file");
	map = get_next_line(fd);
	if (check_map(map) == false)
		ft_error("Invalid map");
	return (map);
}

int	main(int argc, char **argv)
{
	char	*map;

	if (argc < 2)
		ft_error("No map file");
	map = read_map(argv[1]);
	ft_printf("%s\n", map);
	// mlx();
	return (0);
}