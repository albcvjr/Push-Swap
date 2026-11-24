/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:35 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/24 13:10:34 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Descripcion:
		La funcion ft_pa mueve de el nodo primero de
		benchmark->stack_a al benchmark->stack_b.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_pa(t_benchmark *benchmark)
{
	t_list	*node;

	if (benchmark == NULL)
		return ;
	node = ft_pop_first(&benchmark->stack_b);
	if (node == NULL)
		return ;
	ft_lstadd_front(&benchmark->stack_a, node);
}

/* 
	Descripcion:
		La funcion ft_pb mueve de el nodo primero de
		benchmark->stack_b al benchmark->stack_a.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_pb(t_benchmark *benchmark)
{
	t_list	*node;

	if (benchmark == NULL)
		return ;
	node = ft_pop_first(&benchmark->stack_a);
	if (node == NULL)
		return ;
	ft_lstadd_front(&benchmark->stack_b, node);
}
