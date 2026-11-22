/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:46:49 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/22 22:41:24 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_number_size(int number)
{
	int	i;

	i = 1;
	while (number / 10 != 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

int	ft_flag_i(int arg, int fd)
{
	int	count;

	count = _number_size(arg);
	if (arg < 0)
	{
		count++;
	}
	ft_putnbr_fd(arg, fd);
	return (count);
}
