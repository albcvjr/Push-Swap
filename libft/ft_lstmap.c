/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:07:55 by dbenjume          #+#    #+#             */
/*   Updated: 2026/10/12 17:19:07 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	void	*new_content;

	if (!lst || !del || !f)
		return (NULL);
	new_content = f(lst->content);
	ret = ft_lstnew(new_content);
	if (!ret)
	{
		del(new_content);
		return (NULL);
	}
	if (lst->next)
	{
		ret->next = ft_lstmap(lst->next, f, del);
		if (!ret->next)
		{
			ft_lstdelone(ret, del);
			return (NULL);
		}
	}
	return (ret);
}
