/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:52:50 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/11 16:54:54 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*data;
	unsigned char	uc;

	data = s;
	uc = c;
	while (n)
	{
		data[n - 1] = uc;
		n--;
	}
	return (s);
}
