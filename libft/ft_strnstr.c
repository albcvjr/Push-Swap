/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:02:00 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/11 17:00:31 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	u;
	size_t	size_little;

	size_little = ft_strlen(little);
	if (!size_little)
		return ((char *)big);
	i = 0;
	while (big[i] && i + size_little <= len)
	{
		u = 0;
		while ((big[i + u] && little[u]) && big[i + u] == little[u])
			u++;
		if (u == size_little)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
