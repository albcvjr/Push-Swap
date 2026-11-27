/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 00:12:18 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 20:45:21 by dbenjume         ###   ########.fr       */
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
int	ft_strisint(char *str)
{
	char	*to_str;
	int		ret;

	to_str = ft_itoa(ft_atoi(str));
	if (!to_str)
		return (0);
	ret = ft_strncmp(to_str, str, ft_strlen(str) + 1) == 0;
	free(to_str);
	return (ret);
}
