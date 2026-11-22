/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:59:01 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/11 17:00:15 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*needle;
	unsigned char	uc;

	needle = NULL;
	uc = c;
	while (*s)
	{
		if (*s == uc)
			needle = (char *)s;
		s++;
	}
	if (*s == uc)
		needle = (char *)s;
	return (needle);
}
