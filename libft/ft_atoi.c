/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 01:01:35 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/12 17:07:47 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*_ft_skip_space(char *nptr)
{
	while (*nptr && ((*nptr > 8 && *nptr < 14) || *nptr == ' '))
		nptr++;
	return (nptr);
}

static int	_ft_is_sign(unsigned char c)
{
	if ((c == '-') || c == '+')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	sign;

	sign = 1;
	ret = 0;
	nptr = _ft_skip_space((char *)nptr);
	if (_ft_is_sign(*nptr))
	{
		sign = (*nptr - 44) * -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		ret = ret * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * ret);
}
