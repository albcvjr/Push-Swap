/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 22:28:51 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/11 18:36:16 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*mem;
	size_t	size;

	size = ft_strlen(s) + 1;
	mem = ft_calloc(size, sizeof(char));
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s, size);
	return (mem);
}
