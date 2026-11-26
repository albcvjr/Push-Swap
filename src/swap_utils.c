/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:23 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/26 19:40:05 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Descripcion:
		La funcion ft_sa cambia de lugar el primero y segundo nodo de
		benchmark->index_a.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_sa(t_benchmark *benchmark)
{
	t_list	*n1;
	t_list	*n2;

	n1 = ft_pop_first(&benchmark->index_a);
	n2 = ft_pop_first(&benchmark->index_a);
	ft_lstadd_front(&benchmark->index_a, n1);
	ft_lstadd_front(&benchmark->index_a, n2);
	ft_printf("sa\n");
	benchmark->sa += 1;
}

/*
	Descripcion:
		La funcion ft_sb cambia de lugar el primero y segundo nodo de
		benchmark->index_b.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_sb(t_benchmark *benchmark)
{
	t_list	*n1;
	t_list	*n2;

	n1 = ft_pop_first(&benchmark->index_b);
	n2 = ft_pop_first(&benchmark->index_b);
	ft_lstadd_front(&benchmark->index_b, n1);
	ft_lstadd_front(&benchmark->index_b, n2);
	ft_printf("sb\n");
	benchmark->sa += 1;
}

/*
	Descripcion:
		La funcion ft_ss cambia de lugar el primero y segundo nodo de
		benchmark->index_a y benchmark->index_b.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_ss(t_benchmark *benchmark)
{
	t_list	*n1;
	t_list	*n2;

	n1 = ft_pop_first(&benchmark->index_a);
	n2 = ft_pop_first(&benchmark->index_a);
	ft_lstadd_front(&benchmark->index_a, n1);
	ft_lstadd_front(&benchmark->index_a, n2);
	n1 = ft_pop_first(&benchmark->index_b);
	n2 = ft_pop_first(&benchmark->index_b);
	ft_lstadd_front(&benchmark->index_b, n1);
	ft_lstadd_front(&benchmark->index_b, n2);
	ft_printf("ss\n");
	benchmark->ss += 1;
}
