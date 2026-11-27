/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 22:21:26 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 23:16:24 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bunus.h"
# include "get_next_line.h"

int	main(int argc, char **argv)
{
	t_benchmark	benchmark;
	int			i;
	char 		*input;

	ft_init_benchmark(&benchmark);
	i = 1;
	while (i < argc)
	{
		if (!ft_update_benchmark(argv[i++], &benchmark))
		{
			ft_clear_benchmark(&benchmark);
			ft_printfe(ERROR_MSG);
			return (1);
		}
	}
	input = get_next_line(1);
	while (!input || !*input)
	{
		free(input);
		input = get_next_line(1);		
	}
	if (ft_compute_disorder(benchmark.stack_a) && !ft_lstsize(benchmark.stack_b))
		ft_printf("OK");
	else
		ft_printfe(ERROR_MSG);
	ft_clear_benchmark(&benchmark);
	return (0);
}