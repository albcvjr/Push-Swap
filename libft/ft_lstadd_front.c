/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:05:05 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/19 21:51:17 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*second;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	second = *lst;
	*lst = new;
	new->next = second;
}
