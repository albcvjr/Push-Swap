/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:56:07 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/11 16:58:39 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		size_src;
	const char	*old_src;

	old_src = src;
	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	i = 0;
	while (*src && i < size - 1)
	{
		*dst = *src;
		src++;
		dst++;
		i++;
	}
	*dst = 0;
	if (src < dst)
		return (ft_strlen(old_src));
	return (size_src);
}
