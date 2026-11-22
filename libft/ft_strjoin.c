/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:00:56 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/12 17:51:38 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	size_s1;
	size_t	size_s2;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	mem = ft_calloc(size_s1 + size_s2 + 1, sizeof(char));
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s1, sizeof(char) * size_s1);
	ft_memcpy(mem + size_s1, s2, sizeof(char) * size_s2);
	ft_memset(mem + size_s1 + size_s2 + 1, 0, sizeof(char));
	return (mem);
}
