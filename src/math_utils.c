/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 21:56:56 by acuevas           #+#    #+#             */
/*   Updated: 2026/11/26 22:04:37 by acuevas          ###   ########.fr       */
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