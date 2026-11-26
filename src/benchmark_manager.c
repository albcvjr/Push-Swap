/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 22:48:12 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/26 19:51:56 by dbenjume         ###   ########.fr       */
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
	benchmark->index_a = NULL;
	benchmark->index_b = NULL;
	benchmark->disorder = 0;
	benchmark->show_benchmark = 0;
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
		benchmark->sort = ft_chunk_sort;
	}
	else if (ft_strncmp(arg, "--complex", ft_strlen("--complex") + 1) == 0)
	{
		benchmark->strategy = "Complex";
		benchmark->complexety = "O(n log n)";
		benchmark->sort = ft_radix_sort;
	}
	else if (ft_strncmp(arg, "--bench", ft_strlen("--bench") + 1) == 0)
		benchmark->show_benchmark = 1;
	else if (ft_strisint(arg))
		ft_add_node(benchmark, arg);
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
		benchmark->sort = ft_chunk_sort;
	}
	else
	{
		benchmark->complexety = "O(n log n)";
		benchmark->sort = ft_radix_sort;
	}
	ft_update_indexes(benchmark);
}

/*
	Descripcion:
		La funcion ft_print_benchmark mprime los datos del benchmark.

	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_print_benchmark(t_benchmark *benchmark)
{
	char	decimals[3];

	decimals[0] = benchmark->disorder % 10 + '0';
	decimals[1] = benchmark->disorder / 10 % 10 + '0';
	decimals[2] = 0;
	ft_printfe("[bench] disorder:    %i.%s%%\n", benchmark->disorder/100,
		decimals);
	ft_printfe("[bench] strategy:    %s / %s\n", benchmark->strategy,
		benchmark->complexety);
	ft_printfe("[bench] total_ops:    %u\n", benchmark->sa + benchmark->sb +
		benchmark->ss + benchmark->pa + benchmark->pb + benchmark->ra +
		benchmark->rb + benchmark->rr + benchmark->rra + benchmark->rrb +
		benchmark->rrr);
	ft_printfe("[bench] sa:    %u    sb:    %u    ss:    %u    pa:    %u    \
		pb:    %u\n", benchmark->sa, benchmark->sb, benchmark->ss, 
		benchmark->pa, benchmark->pb);
	ft_printfe("[bench] ra:    %u    rb:    %u    rr:    %u    rra:    %u    \
		rrb:    %u    rrr:    %u\n", benchmark->ra, benchmark->rb, 
		benchmark->rr, benchmark->rra, benchmark->rrb, benchmark->rrr);
}

void	ft_clear_benchmark(t_benchmark *benchmark)
{
	ft_lstclear(&(benchmark->stack_a), free);
	ft_lstclear(&(benchmark->index_a), free);
}
