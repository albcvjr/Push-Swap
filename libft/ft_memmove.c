/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:55:22 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/20 22:07:29 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*data_1;
	const unsigned char	*data_2;
	size_t				i;

	i = 0;
	data_1 = dest;
	data_2 = src;
	if (data_1 > data_2)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (i < n)
		{
			data_1[i] = data_2[i];
			i++;
		}
	}
	return (data_1);
}
