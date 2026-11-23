/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 22:48:12 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/23 18:44:49 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_benchmark(t_benchmark *benchmark)
{
	benchmark->fun = NULL;
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

int	ft_update_benchmark(char *arg, t_benchmark *benchmark)
{
	if (ft_strlcmp(arg, "simple", ft_strlen("simple")) == 0)
	{
		benchmark->strategy = "Simple";
		benchmark->complexety = "O(n²)";
		benchmark->fun = ft_selection_sort;		
	}
	else if (ft_strlcmp(arg, "medium", ft_strlen("medium")) == 0)
	{
		benchmark->strategy = "Medium";
		benchmark->complexety = "O(n√n)";
		benchmark->fun = ft_buket_sort;
	}
	else if (ft_strlcmp(arg, "complex", ft_strlen("complex")) == 0)
	{
		benchmark->strategy = "Complex";
		benchmark->complexety = "O(n log n)";
		benchmark->fun = ft_radix_sort;
	}
	else if (ft_strisnum(arg))
		ft_lstadd_front(&benchmark->stack_a, ft_lstnew(ft_atoi(arg)));
	else
		return (1);
	return (0);

}

void	ft_calculate_benchmark(t_benchmark *benchmark)
{
	benchmark->disorder = ft_compute_disorder(benchmark->stack_a);
	if (!benchmark->strategy)
	{
		benchmark->strategy = "Adaptive";
		if (benchmark->disorder < 20)
		{
			benchmark->complexety = "O(n²)";
			benchmark->fun = ft_selection_sort;
		}
		else if (benchmark->disorder < 50)
		{
			benchmark->complexety = "O(n√n)";
			benchmark->fun = ft_buket_sort;
		}
		else
		{
			benchmark->complexety = "O(n log n)";
			benchmark->fun = ft_radix_sort;
		}
	}
}


void	ft_print_benchmark(t_benchmark *benchmark)
{
}