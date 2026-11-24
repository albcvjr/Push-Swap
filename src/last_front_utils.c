/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_front_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:57 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/24 17:42:01 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Descripcion:
		La funcion ft_rra mueve el nodo ultimo al nodo primero del 
		benchmark->stack_a.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/

void	ft_rra(t_benchmark *benchmark)
{
	t_list	*first;
	t_list	*last;
	t_list	*current;

	if (benchmark == NULL || benchmark->stack_a == NULL
		|| benchmark->stack_a->next == NULL)
		return ;
	first = benchmark->stack_a;
	last = ft_lstlast(benchmark->stack_a);
	current = benchmark->stack_a;
	while (current->next != last)
		current = current->next;
	current->next = NULL;
	last->next = first;
	benchmark->stack_a = last;
}

/*
	Descripcion:
		La funcion ft_rrb mueve el nodo ultimo al nodo primero del 
		benchmark->stack_b.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/

void	ft_rrb(t_benchmark *benchmark)
{
	t_list	*first;
	t_list	*last;
	t_list	*current;

	if (benchmark == NULL || benchmark->stack_b == NULL
		|| benchmark->stack_b->next == NULL)
		return ;
	first = benchmark->stack_b;
	last = ft_lstlast(benchmark->stack_b);
	current = benchmark->stack_b;
	while (current->next != last)
		current = current->next;
	current->next = NULL;
	last->next = first;
	benchmark->stack_b = last;
}

/*
	Descripcion:
		La funcion ft_rrr mueve el nodo ultimo al nodo primero del 
		benchmark->stack_a y benchmark->stack_b.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/

void	ft_rrr(t_benchmark *benchmark)
{
	ft_rra(benchmark);
	ft_rrb(benchmark);
}
