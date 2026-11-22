/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:46:49 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/22 22:41:31 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_number_size(size_t number)
{
	int	i;

	i = 1;
	while (number / 16 != 0)
	{
		number /= 16;
		i++;
	}
	return (i);
}

int	ft_flag_p(size_t arg, int fd)
{
	if (!arg)
	{
		ft_putstr_fd("(nil)", 1);
		return (ft_strlen("(nil)"));
	}
	ft_putstr_fd("0x", 1);
	ft_putsizet_map_fd(arg, "0123456789abcdef", fd);
	return (_number_size(arg) + 2);
}
