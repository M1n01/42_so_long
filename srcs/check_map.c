/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:44:43 by minabe            #+#    #+#             */
/*   Updated: 2023/04/30 17:34:35 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

ssize_t	count_map_width(char *map)
{
	size_t	i;
	size_t	j;
	size_t	width;

	i = 0;
	while (map[i] != '\0')
	{
		j = i;
		while (map[j] != '\n' || map[j] != '\0')
		{
			if (width < j - i)
				return (-1);
			j++;
		}
		width = j - i;
		i += j + 1;
	}
	return (width);
}

bool	check_map(char *map)
{
	size_t	i;
	int	exit;
	int	collectible;
	int	start;

	start = 0;
	exit = 0;
	collectible = 0;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'P')
			start++;
		if (map[i] == 'E')
			exit++;
		if (map[i] == 'C')
			collectible++;
		if (map[i] != '0' || map[i] != '1')
			return (false);
		i++;
	}
	if (start != 1 || exit != 1 || collectible < 1)
		return (false);
	return (true);
}
