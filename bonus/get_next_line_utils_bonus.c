/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:27:53 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 23:12:18 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_gnl_memchr(void *s, int c, size_t n)
{
	unsigned char	*data;

	data = s;
	while (n--)
	{
		if (*data == (unsigned char)c)
			return (data);
		data++;
	}
	return (NULL);
}

void	*ft_gnl_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*data_1;
	const unsigned char	*data_2;

	if ((!src && !dest))
		return (NULL);
	data_1 = dest;
	data_2 = src;
	while (n--)
		*data_1++ = *data_2++;
	return (data_1);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	size_s1;
	size_t	size_s2;

	size_s1 = 0;
	size_s2 = 0;
	while (s1 && s1[size_s1])
		size_s1++;
	while (s2 && s2[size_s2])
		size_s2++;
	mem = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!mem)
		return (NULL);
	ft_gnl_memcpy(mem, s1, sizeof(char) * size_s1);
	ft_gnl_memcpy(mem + size_s1, s2, sizeof(char) * size_s2);
	*(mem + size_s1 + size_s2) = 0;
	return (mem);
}

char	*ft_gnl_substr(const char *buffer, ssize_t size)
{
	char	*ret;

	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = 0;
	ft_gnl_memcpy(ret, buffer, size);
	return (ret);
}
