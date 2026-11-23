/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 23:36:05 by acuevas           #+#    #+#             */
/*   Updated: 2026/11/23 00:01:49 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	La funcion pop_node, recibe la direccion de memoria de un puntero t_list
	(para poder modificar la lista original **) y un puntero t_list
	(lista de nodos) y devuelve un puntero t_list. Borra el nodo en concreto,
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

/* La funcion pop_last, recibe la direccion de memoria de un puntero
	t_list (lista de nodos) y devuelve un puntero t_list (una nueva lista con
	ese nodo). Extrae el ultimo nodo de la lista y lo devuelve, utilizando
	pop_node y ft_lstlast, implementada en LIBFT. */

t_list	*ft_pop_last(t_list **list)
{
	if (list == NULL || *list == NULL)
		return (NULL);
	return (pop_node(list, ft_lstlast(*list)));
}

/* La funcion pop_first, recibe la direccion de memoria de un puntero t_list
	y devuelve un puntero t_list. Extrae el primer elemento de la lista y
	retorna ese elemento, utilizando pop_node. */

t_list	*ft_pop_first(t_list **list)
{
	if (list == NULL || *list == NULL)
		return (NULL);
	return (pop_node(list, *list));
}

/* La funcion compute_disorder, recibe un puntero t_list (una lista) y devuelve
	un numero entero. Calcula el desorden de la lista recibida, recorriendo
	esta y comprobando, mediante comparacion de nodos, la cantidad de posiciones
	incorrectas. El total, son todas las comparaciones que hace entre nodos. */

size_t	ft_compute_disorder(t_list *list)
{
	size_t	mistakes;
	size_t	total;
	t_list	*node_i;
	t_list	*node_j;

	mistakes = 0;
	total = 0;
	node_i = list;
	while (node_i->next)
	{
		node_j = node_i->next;
		while (node_j)
		{
			total += 1;
			if (node_i > node_j)
				mistakes += 1;
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
	return (mistakes * 10000 / total);
}
