/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front_last_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:56 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/24 20:42:49 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Descripcion:
		La funcion ft_ra mueve el nodo primero al nodo ultimo del 
		benchmark->stack_a.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/

void	ft_ra(t_benchmark *benchmark)
{
	t_list	*node;

	node = ft_pop_first(&benchmark->stack_a);
	ft_lstadd_back(&benchmark->stack_a, node);
	ft_printf("ra\n");
	benchmark->ra += 1;
}

/* 
	Descripcion:
		La funcion ft_rb mueve el nodo primero al nodo ultimo del 
		benchmark->stack_b.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/

void	ft_rb(t_benchmark *benchmark)
{
	t_list	*node;

	node = ft_pop_first(&benchmark->stack_b);
	ft_lstadd_back(&benchmark->stack_b, node);
	ft_printf("rb\n");
	benchmark->rb += 1;
}

/* 
	Descripcion:
		La funcion ft_rr mueve el nodo primero al nodo ultimo del 
		benchmark->stack_a y benchmark->stack_b.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/

void	ft_rr(t_benchmark *benchmark)
{
	t_list	*node;

	node = ft_pop_first(&benchmark->stack_a);
	ft_lstadd_back(&benchmark->stack_a, node);
	node = ft_pop_first(&benchmark->stack_b);
	ft_lstadd_back(&benchmark->stack_b, node);
	ft_printf("rr\n");
	benchmark->rr += 1;
}
