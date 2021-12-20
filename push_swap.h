/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:25:03 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/20 13:25:05 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# ifndef MAX_SIZE
#  define MAX_SIZE 20
# endif

# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

# ifndef MIN_INT
#  define MIN_INT -2147483648
# endif

void	swap(t_stack *constant, t_stack *support, char *msg);
void	push(t_stack **from, t_stack **to, char *msg);
void	rotate(t_stack **constant, t_stack **support, char *msg);
void	rrotate(t_stack **constant, t_stack **support, char *msg);

void	clean_exit(t_stack *stack_a, t_stack *stack_b, int status);
void	sorting(t_stack **stack_a, t_stack **stack_b);
void	sort3(t_stack **stack_a);
void	sort5(t_stack **stack_a, t_stack **stack_b);
void	sort_big(t_stack **stack_a, t_stack **stack_b, t_stack **limits, int i);

void	push_min(t_stack **stack_a, t_stack **stack_b);
void	get_limit(t_stack **interval, t_stack *stack, int status);
int		get_first(t_stack *stack_a, t_stack *interval);
void	split_stack(t_stack **stack_a, t_stack **stack_b, t_stack *interval);

void	merge_halfs(t_stack **stack_a, t_stack **stack_b,
			t_stack *interval);
void	merge_sort_a(t_stack **stack_a, t_stack **stack_b,
			t_stack *interval);
void	rotate_until_sorted(t_stack **stack_a, t_stack *interval);
int		count_between(t_stack *stack_a, t_stack *interval);
int		get_next(t_stack *stack_a, t_stack **interval);

#endif
