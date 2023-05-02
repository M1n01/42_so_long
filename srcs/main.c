/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:43:24 by minabe            #+#    #+#             */
/*   Updated: 2023/05/02 12:50:47 by minabe           ###   ########.fr       */
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
	char	*map;


	map = get_map(file);
	if (check_map(map) == false)
		ft_error("Invalid map");
	printf("[map]\n%s\n", map);
	mlx(map);
	ft_free(map);
	return ;
}
