/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:34:11 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/09 16:34:12 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# ifndef MIN_INT
#  define MIN_INT -2147483648
# endif

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_stack_new_node(int data);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
int		ft_stack_size(t_stack *stack);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_first(t_stack *stack);
void	ft_stack_remove(t_stack **stack);
void	ft_stack_clear(t_stack **stack);
int		ft_stack_duplicate_int(t_stack *stack);
int		ft_stack_is_sorted(t_stack *stack);
int		ft_stack_max(t_stack *stack_a);
int		ft_stack_min(t_stack *stack_a);
t_stack	*ft_stack_duplicate(t_stack *stack);
int		ft_stack_getval(t_stack *stack, int pos);
int		ft_stack_find(t_stack *stack, int val);
int		ft_stack_has_bigger(t_stack *stack, int value);
void	stack_sort(t_stack **stack);
t_stack	*merge_sort(t_stack *first, t_stack *second);
t_stack	*ft_stack_split(t_stack	*head);

#endif
