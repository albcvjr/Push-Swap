/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front_last_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:56 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 22:56:58 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Descripcion:
		La funcion ft_ra mueve el nodo primero al nodo ultimo del 
		benchmark->index_a.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_ra(t_benchmark *benchmark)
{
	t_list	*node;

	if (ft_lstsize(benchmark->index_a) > 1)
	{
		node = ft_pop_first(&benchmark->index_a);
		ft_lstadd_back(&benchmark->index_a, node);
	}
}

/*
	Descripcion:
		La funcion ft_rb mueve el nodo primero al nodo ultimo del 
		benchmark->index_b.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_rb(t_benchmark *benchmark)
{
	t_list	*node;

	if (ft_lstsize(benchmark->index_b) > 1)
	{
		node = ft_pop_first(&benchmark->index_b);
		ft_lstadd_back(&benchmark->index_b, node);
	}
}

/*
	Descripcion:
		La funcion ft_rr mueve el nodo primero al nodo ultimo del 
		benchmark->index_a y benchmark->index_b.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_rr(t_benchmark *benchmark)
{
	t_list	*node;

	node = ft_pop_first(&benchmark->index_a);
	ft_lstadd_back(&benchmark->index_a, node);
	node = ft_pop_first(&benchmark->index_b);
	ft_lstadd_back(&benchmark->index_b, node);
}
