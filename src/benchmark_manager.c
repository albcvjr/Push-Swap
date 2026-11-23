/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 22:48:12 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/23 22:38:13 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* 
	Descripcion:
		La funcion ft_init_benchmark inicializa los datos del benchmark.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_init_benchmark(t_benchmark *benchmark)
{
	benchmark->sort = NULL;
	benchmark->stack_a = NULL;
	benchmark->stack_b = NULL;
	benchmark->disorder = 0; 
	benchmark->strategy = NULL;
	benchmark->complexety = NULL;
	benchmark->sa = 0;
	benchmark->sb = 0;
	benchmark->ss = 0;
	benchmark->pa = 0;
	benchmark->pb = 0;
	benchmark->ra = 0;
	benchmark->rb = 0;
	benchmark->rr = 0;
	benchmark->rra = 0;
	benchmark->rrb = 0;
	benchmark->rrr = 0;
}

/* 
	Descripcion:
		La funcion ft_update_benchmark actualiza flags del benchmark.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
int	ft_update_benchmark(char *arg, t_benchmark *benchmark)
{
	void	*data;
	void	*node;
	
	if (ft_strncmp(arg, "--simple", ft_strlen("--simple") + 1) == 0)
	{
		benchmark->strategy = "Simple";
		benchmark->complexety = "O(n²)";
		benchmark->sort = ft_selection_sort;		
	}
	else if (ft_strncmp(arg, "--medium", ft_strlen("--medium") + 1) == 0)
	{
		benchmark->strategy = "Medium";
		benchmark->complexety = "O(n√n)";
		benchmark->sort = ft_buket_sort;
	}
	else if (ft_strncmp(arg, "--complex", ft_strlen("--complex") + 1) == 0)
	{
		benchmark->strategy = "Complex";
		benchmark->complexety = "O(n log n)";
		benchmark->sort = ft_radix_sort;
	}
	else if (ft_strisint(arg))
	{
		data = ft_create_data(ft_atoi(arg));
		if (!data)
		{
			ft_clear_benchmark(benchmark);
			return (0);
		}
		node = ft_lstnew(data);
		if (!node)
		{
			ft_clear_data(data);
			ft_clear_benchmark(benchmark);
			return (0);
		}
		ft_lstadd_front(&(benchmark->stack_a), node);
	}
	else
		return (0);
	return (1);
}

/* 
	Descripcion:
		La funcion ft_calculate_benchmark sececciona la estrategia
		si no hay flags.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_calculate_benchmark(t_benchmark *benchmark)
{
	benchmark->disorder = ft_compute_disorder(benchmark->stack_a);
	if (benchmark->strategy)
		return ;
	benchmark->strategy = "Adaptive";
	if (benchmark->disorder < 20)
	{
		benchmark->complexety = "O(n²)";
		benchmark->sort = ft_selection_sort;
	}
	else if (benchmark->disorder < 50)
	{
		benchmark->complexety = "O(n√n)";
		benchmark->sort = ft_buket_sort;
	}
	else
	{
		benchmark->complexety = "O(n log n)";
		benchmark->sort = ft_radix_sort;
	}
}

/* 
	Descripcion:
		La funcion ft_print_benchmark mprime los datos del benchmark.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_print_benchmark(t_benchmark *benchmark)
{
	ft_printfe("Strat: %s\n", benchmark->strategy);
}

void	ft_clear_benchmark(t_benchmark *benchmark)
{
	ft_lstclear(&(benchmark->stack_a), ft_clear_data);
}
