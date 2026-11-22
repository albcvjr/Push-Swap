/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 23:36:05 by acuevas           #+#    #+#             */
/*   Updated: 2026/11/22 15:42:40 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

/* La funcion pop_last, recibe un puntero t_list (lista de nodos) y devuelve un
	puntero t_list. Extrae el ultimo nodo de la lista y lo devuelve. */

t_list	*pop_last(t_list *list)
{
	
}

/* La funcion pop_first, recibe la direccion de memoria de un puntero t_list
	y devuelve un puntero t_list. Extrae el primer elemento de la lista y
	retorna ese elemento. */

t_list	*pop_first(t_list **list)
{
	
}

/* La funcion pop_node, recibe la direccion de memoria de un puntero t_list y
	un puntero t_list (lista de nodos) y devuelve un puntero t_list. Borra el
	nodo anterior, enlaza la lista y devuelve el nodo anterior. */

t_list	*pop_node(t_list **list, t_list *node)
{
	
}

/* La funcion compute_disorder, recibe un puntero t_list y devuelve un
	numero entero. Calcula el desorden de la lista recibida, recorriendo esta
	y comprobando, mediante comparacion de nodos, la cantidad de posiciones
	incorrectas. */

int	compute_disorder(t_list *list)
{
	int		mistakes;
	int		total;
	t_list	node_i;
	t_list	node_j;

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
