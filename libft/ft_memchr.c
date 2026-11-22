/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:00:47 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/12 17:45:14 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*data;
	size_t			i;

	data = (void *)s;
	i = 0;
	while (i < n)
	{
		if (data[i] == (unsigned char)c)
			return (&data[i]);
		i++;
	}
	return (NULL);
}
