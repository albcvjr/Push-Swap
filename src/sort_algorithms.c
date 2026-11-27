/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:46:40 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 21:58:39 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Descripcion:
		La funcion ft_selection_sort ordena los datos de el benchmark->index_a
		en benchmark->index_a usando benchmark->index_b como apoyo,
		tiene una complegidad de O(n * n).

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_selection_sort(t_benchmark *benchmark)
{
	t_list	*min_node;

	while (ft_lstsize(benchmark->index_a) && \
		ft_compute_disorder(benchmark->index_a))
	{
		min_node = ft_lstreduce(benchmark->index_a, ft_min);
		while (benchmark->index_a != min_node)
			ft_ra(benchmark);
		ft_pb(benchmark);
	}
	while (ft_lstsize(benchmark->index_b))
	{
		ft_pa(benchmark);
	}
}

static void	_ft_bring_back(t_benchmark *benchmark)
{
	t_list			*max;
	unsigned int	i;

	max = ft_lstreduce(benchmark->index_b, ft_max);
	i = 0;
	while (benchmark->index_b)
	{
		if (max == benchmark->index_b)
		{
			ft_pa(benchmark);
			max = ft_lstreduce(benchmark->index_b, ft_max);
			while (i != 0)
			{
				ft_rrb(benchmark);
				i--;
			}
		}
		else
		{
			ft_rb(benchmark);
			i++;
		}
	}
}

/*
	Descripcion:
		La funcion ft_chunk_sort ordena los datos de el benchmark->index_a
		en benchmark->index_a usando benchmark->index_b como apoyo,
		tiene una complegidad de O(n * sqrt(n)).

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_chunk_sort(t_benchmark *benchmark)
{
	unsigned int	sqrt;
	unsigned int	i;
	t_list			*end_node;

	if (!ft_compute_disorder(benchmark->index_a))
		return ;
	sqrt = ft_sqrt(ft_lstsize(benchmark->index_a));
	i = 0;
	while (benchmark->index_a)
	{
		end_node = NULL;
		i += sqrt;
		while (benchmark->index_a != end_node)
		{
			if (*(unsigned int *)benchmark->index_a->content < i)
				ft_pb(benchmark);
			else
			{
				if (!end_node)
					end_node = benchmark->index_a;
				ft_ra(benchmark);
			}
		}
	}
	_ft_bring_back(benchmark);
}

/*
	Descripcion:
		La funcion ft_radix_sort ordena los datos de el benchmark->index_a
		en benchmark->index_a usando benchmark->index_b como apoyo,
		tiene una complegidad de O(n log n).

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_radix_sort(t_benchmark *benchmark)
{
	t_list			*end_node;
	unsigned int	mask;

	mask = 1;
	while (ft_compute_disorder(benchmark->index_a))
	{
		end_node = NULL;
		while (benchmark->index_a != end_node)
		{
			if (!(mask & *(unsigned int *) \
				benchmark->index_a->content))
				ft_pb(benchmark);
			else
			{
				if (!end_node)
					end_node = benchmark->index_a;
				ft_ra(benchmark);
			}
		}
		mask = mask << 1;
		while (benchmark->index_b)
			ft_pa(benchmark);
	}
}
