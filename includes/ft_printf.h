/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:05:38 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/22 22:43:12 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(char const *format, ...);
void	ft_putsizet_map_fd(size_t n, char *map, int fd);
void	ft_putuint_map_fd(unsigned int n, char *map, int fd);
int		ft_flag_c(char argm, int fd);
int		ft_flag_d(int arg, int fd);
int		ft_flag_i(int arg, int fd);
int		ft_flag_p(size_t arg, int fd);
int		ft_flag_s(char *arg, int fd);
int		ft_flag_u(unsigned int arg, int fd);
int		ft_flag_x(unsigned int arg, int fd);
int		ft_flag_xc(unsigned int arg, int fd);
int		ft_flag_bad(char arg, int fd);

#endif
