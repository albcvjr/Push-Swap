/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:54:33 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/19 20:46:41 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*data_1;
	const unsigned char	*data_2;

	data_1 = dest;
	data_2 = src;
	while (n)
	{
		data_1[n - 1] = data_2[n - 1];
		n--;
	}
	return (data_1);
}
