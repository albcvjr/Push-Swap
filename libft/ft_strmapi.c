/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:02:35 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/10 02:22:24 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;
	size_t	len;

	if (!s || !f)
		return (NULL);
	ret = ft_strdup(s);
	if (!ret)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		ret[i] = f(i, ret[i]);
		i++;
	}
	return (ret);
}
