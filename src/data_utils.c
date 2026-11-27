/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 20:04:22 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 20:45:47 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*_ft_create_value_data(int data)
{
	int	*ret;

	ret = ft_calloc(1, sizeof(int));
	if (!ret)
		return (NULL);
	*ret = data;
	return (ret);
}

static unsigned int	*_ft_create_value_index(unsigned int data)
{
	unsigned int	*ret;

	ret = ft_calloc(1, sizeof(unsigned int));
	if (!ret)
		return (NULL);
	*ret = data;
	return (ret);
}

static int	_ft_add_node_index(t_benchmark *benchmark)
{
	unsigned int	*data;
	t_list			*node;

	data = _ft_create_value_index(0);
	if (!data)
		return (0);
	node = ft_lstnew(data);
	if (!node)
		return (free(data), 0);
	ft_lstadd_back(&(benchmark->index_a), node);
	return (1);
}

/*
	Descripcion:
		mete un nodo con el valor entero "arg" a el stack_a de el benchmark

	Args:
		t_benchmark *benchmark: datos del benchmark
		char *arg: valor a meter
*/
int	ft_add_node(t_benchmark *benchmark, char *arg)
{
	int		*data;
	t_list	*node;

	data = _ft_create_value_data(ft_atoi(arg));
	if (!data)
		return (0);
	node = ft_lstnew(data);
	if (!node)
		return (free(data), 0);
	ft_lstadd_back(&(benchmark->stack_a), node);
	if (!_ft_add_node_index(benchmark))
		return (free(data), 0);
	return (1);
}

void	ft_update_indexes(t_benchmark *benchmark)
{
	t_list	*aux_index;
	t_list	*aux_data1;
	t_list	*aux_data2;

	aux_index = benchmark->index_a;
	aux_data1 = benchmark->stack_a;
	while (aux_index)
	{
		aux_data2 = benchmark->stack_a;
		while (aux_data2)
		{
			if (*((unsigned int *)aux_data1->content) > \
				*((unsigned int *)aux_data2->content))
				(*((unsigned int *)aux_index->content)) += 1;
			aux_data2 = aux_data2->next;
		}
		aux_index = aux_index->next;
		aux_data1 = aux_data1->next;
	}
}
