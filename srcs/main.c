/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:43:24 by minabe            #+#    #+#             */
/*   Updated: 2023/06/19 14:53:40 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	so_long(char *file);

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_error("No map file.");
	so_long(argv[1]);
	return (0);
}

void	so_long(char *file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		ft_error("Malloc failed.");
	map->map = get_map(file);
	if (ft_strlen(map->map) == 0)
		ft_error("Enpty map.");
	map->width = count_map_width(map->map);
	map->height = count_map_height(map->map);
	check_map(map);
	start_game(map);
	return ;
}
