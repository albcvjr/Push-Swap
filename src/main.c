/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 20:28:25 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/23 22:17:35 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_benchmark benchmark;
	int i;
	
	ft_init_benchmark(&benchmark);
	i = 1;
	while (i < argc)
		if (!ft_update_benchmark(argv[i++], &benchmark))
		{
			ft_printfe("Error");
			return (1);
		}
	ft_calculate_benchmark(&benchmark);
	benchmark.sort(&benchmark);
	ft_print_benchmark(&benchmark);
	ft_clear_benchmark(&benchmark);
	return (0);
}
