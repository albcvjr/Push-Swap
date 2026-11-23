/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:00:37 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/23 22:18:01 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_benchmark
{
	void	(*sort)(struct s_benchmark *);
	t_list	*stack_a;
	t_list	*stack_b;
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
size_t	ft_compute_disorder(t_list *list);
void	ft_sa(t_benchmark *benchmark);
void	ft_sb(t_benchmark *benchmark);
void	ft_ss(t_benchmark *benchmark);
void	ft_pa(t_benchmark *benchmark);
void	ft_pb(t_benchmark *benchmark);
void	ft_ra(t_benchmark *benchmark);
void	ft_rb(t_benchmark *benchmark);
void	ft_rr(t_benchmark *benchmark);
void	ft_rra(t_benchmark *benchmark);
void	ft_rrb(t_benchmark *benchmark);
void	ft_rrr(t_benchmark *benchmark);
void	ft_selection_sort(t_benchmark *benchmark);
void	ft_buket_sort(t_benchmark *benchmark);
void	ft_radix_sort(t_benchmark *benchmark);
int		ft_printfe(char const *format, ...);
void	ft_init_benchmark(t_benchmark *benchmark);
int		ft_update_benchmark(char *arg, t_benchmark *benchmark);
void	ft_calculate_benchmark(t_benchmark *benchmark);
void	ft_clear_benchmark(t_benchmark *benchmark);
int		ft_strisint(char *arg);
void	ft_print_benchmark(t_benchmark *benchmark);
void	ft_clear_data(void *data);
int		*ft_create_data(int data);

#endif
