/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:17:04 by minabe            #+#    #+#             */
/*   Updated: 2023/05/05 22:13:08 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	len1 = strlen(s1);
	len2 = strlen(s2);
	str = calloc(len1 + len2 + 1, sizeof(char));
	if (str == NULL)
		ft_error("malloc failed");
	memcpy(str, s1, len1);
	memcpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}
