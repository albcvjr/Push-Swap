/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_front_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:57 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/23 18:59:12 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Descripcion:
		La funcion ft_rra mueve el nodo ultimo al nodo primero del 
		benchmark->stack_a.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_rra(t_benchmark *benchmark);

/* 
	Descripcion:
		La funcion ft_rrb mueve el nodo ultimo al nodo primero del 
		benchmark->stack_b.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_rrb(t_benchmark *benchmark);

/* 
	Descripcion:
		La funcion ft_rrr mueve el nodo ultimo al nodo primero del 
		benchmark->stack_a y benchmark->stack_b.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_rrr(t_benchmark *benchmark);
