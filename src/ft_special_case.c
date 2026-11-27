/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 21:10:20 by acuevas           #+#    #+#             */
/*   Updated: 2026/11/27 23:24:31 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_special_case(t_benchmark *benchmark)
{
	t_list			*node;
	t_list			*min_node;
	t_list			*max_node;
	unsigned int	len;
	unsigned int	i;

	min_node = ft_lstreduce(benchmark->index_a, ft_min);
	len = ft_lstsize(benchmark->index_a);
	node = benchmark->index_a;
	i = 0;
	while (node != min_node)
	{
		node = node->next;
		i++;
	}
	if (i <= len - i && i != 0)
		ft_ra(benchmark);
	else
		ft_rra(benchmark);
	ft_pb(benchmark);
	while (benchmark->index_b->content)
		ft_pa(benchmark);
}
