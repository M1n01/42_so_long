/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:43:24 by minabe            #+#    #+#             */
/*   Updated: 2023/06/06 19:31:22 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	so_long(char *file);

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_error("No map file");
	so_long(argv[1]);
	return (0);
}

void	so_long(char *file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		ft_error("malloc failed");
	map->map = get_map(file);
	map->width = count_map_width(map->map);
	map->height = count_map_height(map->map);
	if (check_map(map) == false)
		ft_error("Invalid map");
	start_game(map->map);
	return ;
}
