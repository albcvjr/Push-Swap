/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 00:12:18 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/24 18:10:59 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Descripcion:
		La funcion ft_strisint cumprueba que una string es un numero entero 
		positivo o negativo.

	Args:
		char *str: el string a comprobar
*/
int		ft_strisint(char *str)
{
	char *to_str;

	to_str = ft_itoa(ft_atoi(str));
	if (!to_str)
		return (0);
	return (ft_strncmp(to_str, str, ft_strlen(str) + 1) == 0);
}
