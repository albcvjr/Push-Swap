/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:01:19 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/19 20:46:43 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*data_1;
	const unsigned char	*data_2;
	size_t				i;

	data_1 = s1;
	data_2 = s2;
	i = 0;
	while (i < n)
	{
		if (data_1[i] != data_2[i])
			return (data_1[i] - data_2[i]);
		i++;
	}
	return (0);
}
