/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:00:37 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/22 23:21:37 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_benchmark
{
	void (*fun)(t_list *, t_list *, t_benchmark *);
	size_t	disorder;
	char	*strategy;
	char	*complexety;
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}	t_benchmark;

t_list	*ft_pop_last(t_list **list);
t_list	*ft_pop_first(t_list **list);
t_list	*ft_pop_node(t_list **list, t_list *node);
int		ft_compute_disorder(t_list *list);
void	ft_sa(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_sb(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_ss(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_pa(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_pb(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_ra(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_rb(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_rr(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_rra(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_rrb(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_rrr(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_selection_sort(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_buket_sort(t_list *la, t_list *lb, t_benchmark *benchmark);
void	ft_radix_sort(t_list *la, t_list *lb, t_benchmark *benchmark);
int		ft_printfe(char const *format, ...);

#endif
