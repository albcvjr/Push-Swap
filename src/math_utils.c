/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 21:56:56 by acuevas           #+#    #+#             */
/*   Updated: 2026/11/27 21:31:15 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_sqrt(unsigned int number)
{
	unsigned int	nb;

	nb = 0;
	while (nb * nb <= number)
		nb++;
	return (nb - 1);
}

/*
	La funcion compute_disorder, recibe un puntero t_list (una lista) y devuelve
	un numero entero. Calcula el desorden de la lista recibida, recorriendo
	esta y comprobando, mediante comparacion de nodos, la cantidad de posiciones
	incorrectas. El total, son todas las comparaciones que hace entre nodos.
*/
unsigned int	ft_compute_disorder(t_list *list)
{
	unsigned int	mistakes;
	unsigned int	total;
	t_list			*node_i;
	t_list			*node_j;

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
			if (*(unsigned int *)node_i->content > \
				*(unsigned int *)node_j->content)
				mistakes += 1;
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
	return (mistakes * 10000 / total);
}
