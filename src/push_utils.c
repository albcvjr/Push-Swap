/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:35 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/26 19:39:54 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Descripcion:
		La funcion ft_pa mueve de el nodo primero de
		benchmark->index_a al benchmark->index_b.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_pa(t_benchmark *benchmark)
{
	t_list	*node;

	node = ft_pop_first(&benchmark->index_b);
	ft_lstadd_front(&benchmark->index_a, node);
	ft_printf("pa\n");
	benchmark->pa += 1;
}

/*
	Descripcion:
		La funcion ft_pb mueve de el nodo primero de
		benchmark->index_b al benchmark->index_a.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_pb(t_benchmark *benchmark)
{
	t_list	*node;

	node = ft_pop_first(&benchmark->index_a);
	ft_lstadd_front(&benchmark->index_b, node);
	ft_printf("pb\n");
	benchmark->pb += 1;
}
