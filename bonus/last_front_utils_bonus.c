/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_front_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:57 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 22:56:48 by dbenjume         ###   ########.fr       */
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
}
