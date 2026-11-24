/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:23 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/24 20:49:11 by acuevas          ###   ########.fr       */
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

	n1 = ft_pop_first(&benchmark->stack_a);
	n2 = ft_pop_first(&benchmark->stack_a);
	ft_lstadd_front(&benchmark->stack_a, n1);
	ft_lstadd_front(&benchmark->stack_a, n2);
	ft_printf("sa\n");
	benchmark->sa += 1;
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

	n1 = ft_pop_first(&benchmark->stack_b);
	n2 = ft_pop_first(&benchmark->stack_b);
	ft_lstadd_front(&benchmark->stack_b, n1);
	ft_lstadd_front(&benchmark->stack_b, n2);
	ft_printf("sb\n");
	benchmark->sa += 1;
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
	t_list	*n1;
	t_list	*n2;

	n1 = ft_pop_first(&benchmark->stack_a);
	n2 = ft_pop_first(&benchmark->stack_a);
	ft_lstadd_front(&benchmark->stack_a, n1);
	ft_lstadd_front(&benchmark->stack_a, n2);
	n1 = ft_pop_first(&benchmark->stack_b);
	n2 = ft_pop_first(&benchmark->stack_b);
	ft_lstadd_front(&benchmark->stack_b, n1);
	ft_lstadd_front(&benchmark->stack_b, n2);
	ft_printf("ss\n");
	benchmark->ss += 1;
}
