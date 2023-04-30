/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:20:57 by minabe            #+#    #+#             */
/*   Updated: 2023/04/30 17:37:30 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*gnl_read(char *save, int fd);
static char	*get_line(char *save);
static char	*get_save(char *save);

char	*get_next_line(int fd)
{
	char		*res;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (save == NULL)
	{
		save = malloc(sizeof(char) * 1);
		if (save == NULL)
			ft_error("malloc failed");
		save[0] = '\0';
	}
	save = gnl_read(save, fd);
	res = get_line(save);
	save = get_save(save);
	return (res);
}

static char	*gnl_read(char *save, int fd)
{
	ssize_t	rc;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		ft_error("malloc failed");
	rc = 1;
	while (ft_strchr(save, '\n') == NULL && rc != 0)
	{
		rc = read(fd, buf, BUFFER_SIZE);
		if (rc == -1)
		{
			ft_free(buf);
			ft_free(save);
			ft_error("read failed");
		}
		buf[rc] = '\0';
		save = ft_strjoin(save, buf);
	}
	ft_free(buf);
	return (save);
}

static char	*get_line(char *save)
{
	char	*line;
	char	*find;

	find = ft_strchr(save, '\n');
	if (find == NULL && *save == '\0')
		return (NULL);
	else if (find == NULL && *save != '\0')
	{
		line = malloc(sizeof(char) * (ft_strlen(save) + 1));
		if (line == NULL)
			ft_error("malloc failed");
		ft_strlcpy(line, save, ft_strlen(save) + 1);
		return (line);
	}
	line = malloc(sizeof(char) * (find - save + 2));
	if (line == NULL)
		ft_error("malloc failed");
	ft_strlcpy(line, save, find - save + 2);
	return (line);
}

static char	*get_save(char *save)
{
	char	*str;
	char	*find;
	char	*res;
	size_t	len;

	find = ft_strchr(save, '\n');
	if (find == NULL)
	{
		ft_free(save);
		return (NULL);
	}
	str = find + 1;
	len = ft_strlen(str);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		ft_error("malloc failed");
	ft_strlcpy(res, str, len + 1);
	ft_free(save);
	return (res);
}
