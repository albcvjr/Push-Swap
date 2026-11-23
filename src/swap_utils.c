/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 21:43:23 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/23 18:55:29 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
	Descripcion:
		La funcion ft_sa cambia de lugar el primero y segundo nodo de
		benchmark->stack_a.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_sa(t_benchmark *benchmark);

/* 
	Descripcion:
		La funcion ft_sb cambia de lugar el primero y segundo nodo de
		benchmark->stack_b.
		
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_sb(t_benchmark *benchmark);

/* 
	Descripcion:
		La funcion ft_ss cambia de lugar el primero y segundo nodo de
		benchmark->stack_a y benchmark->stack_b.
	
	Args:
		t_benchmark *benchmark: datos del benchmark
*/
void	ft_ss(t_benchmark *benchmark);
