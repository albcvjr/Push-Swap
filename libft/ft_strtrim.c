/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:01:21 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/20 21:34:17 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	size_t	trim;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(set);
	while (ft_memchr(set, *s1, size))
		s1++;
	size = ft_strlen(s1);
	trim = 0;
	i = 0;
	while (i < size)
	{
		if (ft_strchr(set, s1[i]))
			trim++;
		else
			trim = 0;
		i++;
	}
	return (ft_substr(s1, 0, size - trim));
}
