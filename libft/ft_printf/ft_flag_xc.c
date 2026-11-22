/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_xc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:46:49 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/22 22:42:03 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_number_size(unsigned int number)
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

int	ft_flag_xc(unsigned int arg, int fd)
{
	ft_putuint_map_fd(arg, "0123456789ABCDEF", fd);
	return (_number_size(arg));
}
