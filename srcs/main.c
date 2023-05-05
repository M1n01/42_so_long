/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:43:24 by minabe            #+#    #+#             */
/*   Updated: 2023/05/05 22:31:49 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

// int	deal_key(int key, void *param)
// {
// 	ft_putchar('X');
// 	(void)key;
// 	(void)param;
// 	return (0);
// }

// int	main()
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
// 	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
// 	mlx_key_hook(win_ptr, deal_key, NULL);
// 	mlx_loop(mlx_ptr);
// 	return (0);
// }

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
	mlx(map);
	printf("[complete map]\n%s\n", map);
	ft_free(map);
	// system("leaks so_long");
	return ;
}
