/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_map_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:47:13 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/31 14:04:14 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_ft_print_digit(unsigned int n, size_t size, char *map, int fd)
{
	if (n / size > 0)
		_ft_print_digit(n / size, size, map, fd);
	ft_putchar_fd(map[n % size], fd);
}

void	ft_putuint_map_fd(unsigned int n, char *map, int fd)
{
	size_t			size;

	if (!map || !*map)
		map = "0123456789";
	size = ft_strlen(map);
	_ft_print_digit(n, size, map, fd);
}
