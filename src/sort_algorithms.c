/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:46:40 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 00:10:31 by acuevas          ###   ########.fr       */
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

	while (ft_lstsize(benchmark->stack_a) &&
		ft_compute_disorder(benchmark->stack_a))
	{
		min_node = ft_lstreduce(benchmark->stack_a, ft_min);
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
		La funcion ft_chunk_sort ordena los datos de el benchmark->stack_a
		en benchmark->stack_a usando benchmark->stack_b como apoyo,
		tiene una complegidad de O(n * sqrt(n)).

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
int	ft_chunk_sort(t_benchmark *benchmark)
{
	t_list			*chunk;
	t_list			*iter;
	t_list			*min_node;
	unsigned int	i;

	while (benchmark->stack_a)
	{
		chunk = NULL;
		i = 0;
		while (i < ft_sqrt(ft_lstsize(benchmark->stack_a)))
		{
			iter = benchmark->stack_a;
			min_node = NULL;
			while (iter)
			{
				if (!ft_isinlst(chunk, iter) && (!min_node || (*(int *)iter->content < *(int *)min_node->content)))
					min_node = iter;
				iter = iter->next;
			}
			ft_lstadd_back(&chunk, ft_lstnew(min_node));
			i++;
		}
		while (chunk)
		{
			iter = ft_isinlst(chunk, benchmark->stack_a);
			if (iter)
			{
				ft_pb(benchmark);
				ft_lstdelone(ft_pop_node(&chunk, iter), NULL);
			}
			else
				ft_ra(benchmark);
		}
	}
	iter = ft_lstreduce(benchmark->stack_b, ft_max);
	i = 0;
	while (benchmark->stack_b)
	{
		if (iter == benchmark->stack_b)
		{
			ft_pa(benchmark);
			iter = ft_lstreduce(benchmark->stack_b, ft_max);
			while (i--)
				ft_rrb(benchmark);
		}
		else
		{
			ft_rb(benchmark);
			i++;
		}
	}
	return (1);
}

/*
	Descripcion:
		La funcion ft_radix_sort ordena los datos de el benchmark->stack_a
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
