/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:53:18 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 22:38:11 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	_ft_add_new_line(char **str, t_fd_data *fdd)
{
	char	*ret2;
	char	*retjoin;
	char	*next_new_line;

	next_new_line = ft_gnl_memchr(fdd->b + (fdd->s), '\n', fdd->e - fdd->s);
	if (next_new_line)
	{
		ret2 = ft_gnl_substr(fdd->b + fdd->s, next_new_line - fdd->b - fdd->s + 1);
		if (!ret2)
		{
			free(*str);
			return (-1);
		}
		retjoin = ft_gnl_strjoin(*str, ret2);
		free(*str);
		free(ret2);
		if (!retjoin)
			return (-1);
		fdd->s = next_new_line - fdd->b + 1;
		*str = retjoin;
		return (0);
	}
	return (1);
}

static int	_ft_add_no_new_line(char **str, t_fd_data *fdd)
{
	char		*ret2;
	char		*retjoin;

	ret2 = ft_gnl_substr(fdd->b + fdd->s, fdd->e - fdd->s);
	if (!ret2)
	{
		free(*str);
		return (-1);
	}
	retjoin = ft_gnl_strjoin(*str, ret2);
	free(*str);
	free(ret2);
	if (!retjoin)
		return (-1);
	fdd->s = fdd->e;
	*str = retjoin;
	return (1);
}

static ssize_t	_get_fd(int fd, t_fd_data *fdd, char *str)
{
	if (fdd->s >= fdd->e)
	{
		fdd->e = read(fd, fdd->b, BUFFER_SIZE);
		fdd->s = 0;
		if (fdd->e == -1)
			free(str);
		return (fdd->e);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_fd_data	fd_data;
	char				*ret;
	int					out;

	ret = 0;
	if (fd < 0)
		return (NULL);
	if (_get_fd(fd, &fd_data, ret) == -1 || (&fd_data)->e == 0)
		return (NULL);
	while ((&fd_data)->s < (&fd_data)->e)
	{
		out = _ft_add_new_line(&ret, &fd_data);
		if (!out)
			return (ret);
		if (out == -1)
			return (NULL);
		if (_ft_add_no_new_line(&ret, &fd_data) == -1)
			return (NULL);
		if (_get_fd(fd, &fd_data, ret) == -1)
			return (NULL);
	}
	return (ret);
}
