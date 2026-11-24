/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenjume <dbenjume@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:00:37 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/24 21:29:20 by dbenjume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef ERROR_MSG
#  define ERROR_MSG "Error"
# endif

# include "libft.h"
# include "ft_printf.h"

typedef struct s_benchmark
{
	int	(*sort)(struct s_benchmark *);
	t_list	*stack_a;
	t_list	*stack_b;
	size_t	disorder;
	char	*strategy;
	char	*complexety;
	int		show_benchmark;
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
t_list	*ft_lstreduce(t_list *list, t_list *(*f)(t_list *node1, t_list *node2));
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
int		ft_selection_sort(t_benchmark *benchmark);
int		ft_buket_sort(t_benchmark *benchmark);
int		ft_radix_sort(t_benchmark *benchmark);
int		ft_printfe(char const *format, ...);
void	ft_init_benchmark(t_benchmark *benchmark);
int		ft_update_benchmark(char *arg, t_benchmark *benchmark);
void	ft_calculate_benchmark(t_benchmark *benchmark);
void	ft_clear_benchmark(t_benchmark *benchmark);
int		ft_strisint(char *str);
void	ft_print_benchmark(t_benchmark *benchmark);
int		*ft_create_data(int data);
t_list	*min(t_list *node1, t_list *node2);

#endif
