/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:59:29 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/11 17:00:23 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (n > len_s1 && n > len_s2)
	{
		if (len_s1 > len_s2)
			return (ft_memcmp(s1, s2, len_s2 + 1));
		else
			return (ft_memcmp(s1, s2, len_s1 + 1));
	}
	else
		return (ft_memcmp(s1, s2, n));
}
