/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:00:31 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/12 17:58:43 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	limit;

	if (!s)
		return (NULL);
	limit = ft_strlen(s);
	if (start > limit)
		return (ft_strdup(""));
	s += start;
	limit -= start;
	if (len > limit)
		len = limit;
	mem = ft_calloc(len + 1, sizeof(char));
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s, len);
	ft_memset(mem + len, 0, 1);
	return (mem);
}
