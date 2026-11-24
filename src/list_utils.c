/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 23:36:05 by acuevas           #+#    #+#             */
/*   Updated: 2026/11/24 13:17:28 by acuevas          ###   ########.fr       */
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
	La funcion compute_disorder, recibe un puntero t_list (una lista) y devuelve
	un numero entero. Calcula el desorden de la lista recibida, recorriendo
	esta y comprobando, mediante comparacion de nodos, la cantidad de posiciones
	incorrectas. El total, son todas las comparaciones que hace entre nodos.
*/
size_t	ft_compute_disorder(t_list *list)
{
	size_t	mistakes;
	size_t	total;
	t_list	*node_i;
	t_list	*node_j;

	if (list == NULL || list->next == NULL)
		return (0);
	mistakes = 0;
	total = 0;
	node_i = list;
	while (node_i->next)
	{
		node_j = node_i->next;
		while (node_j)
		{
			total += 1;
			if (*(int *)node_i->content > *(int *)node_j->content)
				mistakes += 1;
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
	return (mistakes * 10000 / total);
}
