/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:00:37 by dbenjume          #+#    #+#             */
/*   Updated: 2026/11/27 00:09:44 by acuevas          ###   ########.fr       */
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
	t_list			*stack_a;
	t_list			*stack_b;
	t_list			*index_a;
	t_list			*index_b;
	unsigned int	disorder;
	char			*strategy;
	char			*complexety;
	int				show_benchmark;
	unsigned int	sa;
	unsigned int	sb;
	unsigned int	ss;
	unsigned int	pa;
	unsigned int	pb;
	unsigned int	ra;
	unsigned int	rb;
	unsigned int	rr;
	unsigned int	rra;
	unsigned int	rrb;
	unsigned int	rrr;
}	t_benchmark;

t_list			*ft_pop_last(t_list **list);
t_list			*ft_pop_first(t_list **list);
t_list			*ft_pop_node(t_list **list, t_list *node);
t_list			*ft_lstreduce(t_list *list, t_list *(*f)(t_list *node1, t_list *node2));
unsigned int	ft_compute_disorder(t_list *list);
void			ft_sa(t_benchmark *benchmark);
void			ft_sb(t_benchmark *benchmark);
void			ft_ss(t_benchmark *benchmark);
void			ft_pa(t_benchmark *benchmark);
void			ft_pb(t_benchmark *benchmark);
void			ft_ra(t_benchmark *benchmark);
void			ft_rb(t_benchmark *benchmark);
void			ft_rr(t_benchmark *benchmark);
void			ft_rra(t_benchmark *benchmark);
void			ft_rrb(t_benchmark *benchmark);
void			ft_rrr(t_benchmark *benchmark);
int				ft_selection_sort(t_benchmark *benchmark);
int				ft_chunk_sort(t_benchmark *benchmark);
int				ft_radix_sort(t_benchmark *benchmark);
int				ft_printfe(char const *format, ...);
void			ft_init_benchmark(t_benchmark *benchmark);
int				ft_update_benchmark(char *arg, t_benchmark *benchmark);
void			ft_calculate_benchmark(t_benchmark *benchmark);
void			ft_clear_benchmark(t_benchmark *benchmark);
int				ft_strisint(char *str);
void			ft_print_benchmark(t_benchmark *benchmark);
void			ft_update_indexes(t_benchmark *benchmark);
t_list			*ft_min(t_list *node1, t_list *node2);
t_list			*ft_max(t_list *node1, t_list *node2);
int				ft_add_node(t_benchmark *benchmark, char *arg);
unsigned int	ft_sqrt(unsigned int number);
t_list			*ft_isinlst(t_list *list, void *value);

#endif
