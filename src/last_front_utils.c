/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_front_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:57 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 21:14:31 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Descripcion:
		La funcion ft_rra mueve el ultimo nodo a la posicion del primer
		nodo de benchmark->index_a.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_rra(t_benchmark *benchmark)
{
	t_list	*node;

	if (ft_lstsize(benchmark->index_a) > 1)
	{
		node = ft_pop_last(&benchmark->index_a);
		ft_lstadd_front(&benchmark->index_a, node);
		ft_printf("rra\n");
		benchmark->rra += 1;
	}
}

/*
	Descripcion:
		La funcion ft_rrb mueve el nodo ultimo al nodo primero del 
		benchmark->index_b.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_rrb(t_benchmark *benchmark)
{
	t_list	*node;

	if (ft_lstsize(benchmark->index_b) > 1)
	{
		node = ft_pop_last(&benchmark->index_b);
		ft_lstadd_front(&benchmark->index_b, node);
		ft_printf("rrb\n");
		benchmark->rrb += 1;
	}
}

/*
	Descripcion:
		La funcion ft_rrr mueve el nodo ultimo al nodo primero del 
		benchmark->index_a y benchmark->index_b.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_rrr(t_benchmark *benchmark)
{
	t_list	*node;

	node = ft_pop_last(&benchmark->index_a);
	ft_lstadd_front(&benchmark->index_a, node);
	node = ft_pop_last(&benchmark->index_b);
	ft_lstadd_front(&benchmark->index_b, node);
	ft_printf("rrr\n");
	benchmark->rrr += 1;
}
