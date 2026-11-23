/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 00:12:18 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/23 22:30:06 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Descripcion:
		La funcion ft_strisint cumprueba que una string es un numero entero 
		positivo o negativo.
	
	Args:
		char *arg: rl string a comprobar
*/
int		ft_strisint(char *arg)
{
	char to_str;

	to_str = ft_itoa(ft_atoi(arg));
	return (ft_strncmp(to_str, arg, ft_strlen(arg) + 1) == 0);
}
