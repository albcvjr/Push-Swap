/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 20:45:49 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 20:47:59 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Descripcion:
		devuelve el nodo minimo

	Args:
		t_list *node1: nodo 1
		t_list *node2: nodo 2
*/
t_list	*ft_min(t_list *ret, t_list *node)
{
	if (!ret)
		return (node);
	if (*((unsigned int *)ret->content) < *((unsigned int *)node->content))
		return (ret);
	return (node);
}

/*
	Descripcion:
		devuelve el nodo maximo

	Args:
		t_list *node1: nodo 1
		t_list *node2: nodo 2
*/
t_list	*ft_max(t_list *ret, t_list *node)
{
	if (!ret)
		return (node);
	if (*((unsigned int *)ret->content) > *((unsigned int *)node->content))
		return (ret);
	return (node);
}
