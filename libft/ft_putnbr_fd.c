/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:04:40 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/20 21:25:03 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_ft_print_digit(unsigned int n, int fd)
{
	if (n / 10 > 0)
		_ft_print_digit(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", sizeof(char));
	}
	_ft_print_digit(n, fd);
}
