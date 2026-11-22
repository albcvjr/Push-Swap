/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:02:09 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/19 18:36:50 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_ft_10_log(int n)
{
	int	i;
	int	l;

	l = 0;
	i = 1;
	while (n / i > 9)
	{
		i = i * 10;
		l++;
	}
	return (l);
}

static void	_ft_create_str(char *str, int n, int len)
{
	while (len >= 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		log_10;
	char	*ret;
	int		is_negative;

	is_negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		is_negative = 1;
	}
	log_10 = _ft_10_log(n);
	ret = ft_calloc(log_10 + 2 + is_negative, sizeof(char));
	if (!ret)
		return (NULL);
	if (is_negative)
		ret[0] = '-';
	ret[log_10 + 2 + is_negative] = 0;
	_ft_create_str(ret + is_negative, n, log_10);
	return (ret);
}
