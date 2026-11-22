/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:56:35 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/11 16:58:51 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		size_dst;
	size_t		size_src;
	const char	*old_src;

	old_src = src;
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size <= size_dst)
		return (size_src + size);
	i = size_dst + 1;
	dst += size_dst;
	while (*src && i < size)
	{
		*dst = *src;
		src++;
		dst++;
		i++;
	}
	*dst = 0;
	size_src = ft_strlen(old_src);
	return (size_dst + size_src);
}
