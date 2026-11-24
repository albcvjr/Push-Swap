/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:01:52 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/24 19:03:54 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int value)
{
	int		*number;
	t_list	*node;

	number = malloc(sizeof(int));
	if (number == NULL)
		return (NULL);
	*number = value;
	node = ft_lstnew(number);
	if (node == NULL)
	{
		free(number);
		return (NULL);
	}
	return (node);
}

void	print_stack(t_list *stack)
{
	t_list	*current;
	
	current = stack;
	while (current != NULL)
	{
		ft_printf("%d\n", *(int *)current->content);
		current = current->next;
	}
}

int	main(void)
{
	t_list	*node;
	t_benchmark	benchmark;
	
	ft_init_benchmark(&benchmark);
	node = new_node(42);
	ft_lstadd_back(&benchmark.stack_a, node);
	ft_printf("añadido 1\n");
	
	node = new_node(43);
	ft_lstadd_back(&benchmark.stack_a, node);
	ft_printf("añadido 2\n");
	
	node = new_node(44);
	ft_lstadd_back(&benchmark.stack_a, node);
	ft_printf("añadido 3\n");
	print_stack(benchmark.stack_a);
	ft_selection_sort(&benchmark);
	ft_print_benchmark(&benchmark);
	ft_lstclear(&benchmark.stack_a, free);
	return (0);
}
