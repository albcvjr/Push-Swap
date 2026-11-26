/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_disorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:01:52 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/26 18:04:01 by acuevas          ###   ########.fr       */
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
	t_list	*stack;
	t_list	*node;

	stack = NULL;
	node = new_node(42);
	if (node == NULL)
	{
		ft_lstclear(&stack, free);
		return (1);
	}
	ft_lstadd_front(&stack, node);
	ft_printf("añadido 1\n");

	node = new_node(43);
	if (node == NULL)
	{
		ft_lstclear(&stack, free);
		return (1);
	}
	ft_lstadd_front(&stack, node);
	ft_printf("añadido 2\n");

	node = new_node(44);
	if (node == NULL)
	{
		ft_lstclear(&stack, free);
		return (1);
	}
	ft_lstadd_front(&stack, node);
	ft_printf("añadido 3\n");
	print_stack(stack);
	ft_printfe("%t\n", ft_compute_disorder(stack));
	ft_lstclear(&stack, free);
	return (0);
}
