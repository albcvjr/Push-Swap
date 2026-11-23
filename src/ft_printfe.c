/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 22:45:41 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/22 23:23:10 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_type_flag(va_list args, const char *format, int fd)
{
	if (*format == 'c')
		return (ft_flag_c(va_arg(args, int), fd));
	else if (*format == 's')
		return (ft_flag_s(va_arg(args, char *), fd));
	else if (*format == 'p')
		return (ft_flag_p(va_arg(args, size_t), fd));
	else if (*format == 'd')
		return (ft_flag_d(va_arg(args, int), fd));
	else if (*format == 'i')
		return (ft_flag_i(va_arg(args, int), fd));
	else if (*format == 'u')
		return (ft_flag_u(va_arg(args, unsigned int), fd));
	else if (*format == 'x')
		return (ft_flag_x(va_arg(args, unsigned int), fd));
	else if (*format == 'X')
		return (ft_flag_xc(va_arg(args, unsigned int), fd));
	else if (*format == '%')
		return (ft_flag_c('%', fd));
	else
		return (ft_flag_bad(*format, fd));
}

static int	check_bounds(size_t start, char const *format, va_list args)
{
	if (start >= ft_strlen(format))
	{
		va_end(args);
		return (0);
	}
	return (1);
}

int	ft_printfe(char const *format, ...)
{
	va_list		args;
	const char	*needle;
	int			size;
	size_t		start;

	if (!format)
		return (-1);
	size = 0;
	start = 0;
	va_start(args, format);
	needle = ft_strchr(format, '%');
	while (needle)
	{
		write(1, format + start, needle - (format + start));
		size += needle - (format + start) + _type_flag(args, needle + 1, 2);
		start = needle - format + 2;
		if (!check_bounds(start, format, args))
			return (size);
		needle = ft_strchr(format + start, '%');
	}
	ft_putstr_fd((char *)(format + start), 2);
	size += ft_strlen(format + start);
	va_end(args);
	return (size);
}
