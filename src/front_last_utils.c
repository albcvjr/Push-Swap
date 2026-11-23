/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front_last_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:56 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/23 19:00:02 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Descripcion:
		La funcion ft_ra mueve el nodo primero al nodo ultimo del 
		benchmark->stack_a.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_ra(t_benchmark *benchmark);

/* 
	Descripcion:
		La funcion ft_rb mueve el nodo primero al nodo ultimo del 
		benchmark->stack_b.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_rb(t_benchmark *benchmark);

/* 
	Descripcion:
		La funcion ft_rr mueve el nodo primero al nodo ultimo del 
		benchmark->stack_a y benchmark->stack_b.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_rr(t_benchmark *benchmark);
