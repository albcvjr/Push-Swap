/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_manager_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 22:48:12 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 22:58:14 by dbenjume         ###   ########.fr       */
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
	benchmark->stack_a = NULL;
	benchmark->stack_b = NULL;
}

/*
	Descripcion:
		La funcion ft_update_benchmark actualiza flags del benchmark.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
int	ft_update_benchmark(char *arg, t_benchmark *benchmark)
{
	if (ft_strisint(arg))
		ft_add_node(benchmark, arg);
	else
		return (0);
	return (1);
}

void	ft_clear_benchmark(t_benchmark *benchmark)
{
	ft_lstclear(&(benchmark->stack_a), free);
	ft_lstclear(&(benchmark->stack_b), free);
}
