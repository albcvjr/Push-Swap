/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 20:04:22 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/23 22:02:44 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Descripcion:
		La funcion ft_clear_data libera la memoria del dato.
	
	Args:
		int *data: puntero del dato
*/
void	ft_clear_data(void *data)
{
	free(data);
}


/* 
	Descripcion:
		La funcion ft_create_data reserva la memoria del dato.
	
	Args:
		int data: valor del dato
*/
int	*ft_create_data(int data)
{
	int	*ret;

	ret = ft_calloc(1, sizeof(int));
	*ret = data;
	return (ret);
}
