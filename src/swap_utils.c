/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:23 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/24 04:05:57 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Descripcion:
		La funcion ft_sa cambia de lugar el primero y segundo nodo de
		benchmark->stack_a.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_sa(t_benchmark *benchmark)
{
	t_list	*n1;
	t_list	*n2;

	if (benchmark == NULL || benchmark->stack_a == NULL
		|| benchmark->stack_a->next == NULL)
		return ;
	n1 = benchmark->stack_a;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	benchmark->stack_a = n2;
}

/* 
	Descripcion:
		La funcion ft_sb cambia de lugar el primero y segundo nodo de
		benchmark->stack_b.
		
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_sb(t_benchmark *benchmark)
{
	t_list	*n1;
	t_list	*n2;

	if (benchmark == NULL || benchmark->stack_b == NULL
		|| benchmark->stack_b->next == NULL)
		return ;
	n1 = benchmark->stack_b;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	benchmark->stack_b = n2;
}

/* 
	Descripcion:
		La funcion ft_ss cambia de lugar el primero y segundo nodo de
		benchmark->stack_a y benchmark->stack_b.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_ss(t_benchmark *benchmark)
{
	ft_sa(benchmark);
	ft_sb(benchmark);
}
