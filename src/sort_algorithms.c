/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:46:40 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/24 21:30:24 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Descripcion:
		La funcion ft_selection_sort ordena los datos de el benchmark->stack_a
		en benchmark->stack_a usando benchmark->stack_b como apoyo,
		tiene una complegidad de O(n * n).
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
int	ft_selection_sort(t_benchmark *benchmark)
{
	t_list *min_node;
	t_list *iter;

	while (ft_lstsize(benchmark->stack_a) && ft_compute_disorder(benchmark->stack_a))
	{
		min_node = ft_lstreduce(benchmark->stack_a, min);
		iter = benchmark->stack_a;
		while(iter != min_node)
		{
			iter = iter->next;			
			ft_ra(benchmark);
		}
		ft_pb(benchmark);
	}
	while (ft_lstsize(benchmark->stack_b))
	{
		ft_pa(benchmark);
	}
	return (1);
}

/* 
	Descripcion:
		La funcion ft_selection_sort ordena los datos de el benchmark->stack_a
		en benchmark->stack_a usando benchmark->stack_b como apoyo,
		tiene una complegidad de O(n * sqrt(n)).
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
int	ft_buket_sort(t_benchmark *benchmark)
{
	ft_pb(benchmark);
	ft_pb(benchmark);
	return (1);
}

/* 
	Descripcion:
		La funcion ft_selection_sort ordena los datos de el benchmark->stack_a
		en benchmark->stack_a usando benchmark->stack_b como apoyo,
		tiene una complegidad de O(n log n).
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
int	ft_radix_sort(t_benchmark *benchmark)
{
	ft_pb(benchmark);
	ft_pb(benchmark);
	ft_pb(benchmark);
	return (1);
}
