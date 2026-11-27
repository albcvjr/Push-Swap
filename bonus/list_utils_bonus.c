/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 23:36:05 by acuevas           #+#    #+#             */
/*   Updated: 2026/11/27 20:42:24 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	La funcion pop_node, borra el nodo en concreto,
	enlaza la lista y devuelve el nodo extraido.

	Args:
		t_list **list: lista original
		t_list *node: nodo a eliminar

	Return: 
		t_list: nodo eliminado
*/
t_list	*ft_pop_node(t_list **list, t_list *node)
{
	t_list	*current;
	t_list	*previous;

	if (list == NULL || *list == NULL || node == NULL)
		return (NULL);
	if (node == *list)
	{
		*list = node->next;
		node->next = NULL;
		return (node);
	}
	current = *list;
	while (current != NULL && current != node)
	{
		previous = current;
		current = current->next;
	}
	if (current == NULL)
		return (NULL);
	previous->next = node->next;
	node->next = NULL;
	return (node);
}

/*
	La funcion pop_last, extrae el ultimo nodo de la lista y lo devuelve,
	utilizando pop_node y ft_lstlast, implementada en LIBFT.

		Args:
		t_list **list: lista original

	Return: 
		t_list: nodo devuelto
*/
t_list	*ft_pop_last(t_list **list)
{
	if (list == NULL || *list == NULL)
		return (NULL);
	return (ft_pop_node(list, ft_lstlast(*list)));
}

/*
	La funcion pop_first, extrae el primer elemento de la lista y
	retorna ese elemento, utilizando pop_node.

		Args:
		t_list **list: lista original

	Return: 
		t_list: nodo devuelto
*/
t_list	*ft_pop_first(t_list **list)
{
	if (list == NULL || *list == NULL)
		return (NULL);
	return (ft_pop_node(list, *list));
}

/*
	Descripcion:
		reduce una lista a un nodo
	Args:
		t_list *list: lista
		t_list *(*f)(t_list *, t_list *): funcion reductora
*/
t_list	*ft_lstreduce(t_list *list, t_list *(*f)(t_list *, t_list *))
{
	t_list	*ret;
	t_list	*iter;

	ret = NULL;
	iter = list;
	while (iter)
	{
		ret = f(ret, iter);
		iter = iter->next;
	}
	return (ret);
}

/*
	Descripcion:
		Retorna 1 si el valor esta en la lista, sino, 0

	Args:
		t_list *list: lista
		void *value: valor
*/
t_list	*ft_isinlst(t_list *list, void *value)
{
	t_list	*iter;

	iter = list;
	while (iter)
	{
		if (iter->content == value)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}
