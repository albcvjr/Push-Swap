/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 20:04:22 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/24 21:30:43 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
	Descripcion:
		devuelve el nodo minimo
	Args:
		t_list *node1: nodo 1
		t_list *node2: nodo 2
*/
t_list *min(t_list *node1, t_list *node2)
{
	if (*((int*)node1->content) < *((int*)node2->content))
		return (node1);
	return (node2);
}
