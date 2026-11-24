/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front_last_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:56 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/24 17:41:35 by acuevas          ###   ########.fr       */
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
	t_list	*first;
	t_list	*last;
	t_list	*new_first;

	if (benchmark == NULL || benchmark->stack_a == NULL
		|| benchmark->stack_a->next == NULL)
		return ;
	first = benchmark->stack_a;
	last = ft_lstlast(benchmark->stack_a);
	new_first = benchmark->stack_a->next;
	last->next = first;
	first->next = NULL;
	benchmark->stack_a = new_first;
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
	t_list	*first;
	t_list	*last;
	t_list	*new_first;

	if (benchmark == NULL || benchmark->stack_b == NULL
		|| benchmark->stack_b->next == NULL)
		return ;
	first = benchmark->stack_b;
	last = ft_lstlast(benchmark->stack_b);
	new_first = benchmark->stack_b->next;
	last->next = first;
	first->next = NULL;
	benchmark->stack_b = new_first;
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
	ft_ra(benchmark);
	ft_rb(benchmark);
}
