/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:28:30 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/09 14:28:33 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_stack_min_value(*stack_a);
	while ((*stack_a)->data != min)
	{
		if ((*stack_a)->data != min && (*stack_a)->next->data != min)
			rrotate(stack_a, 0, "rra\n");
		else
			rotate(stack_a, 0, "ra\n");
	}
	push(stack_a, stack_b, "pb\n");
}

void	get_limit(t_stack **interval, t_stack *stack, int status)
{
	t_stack	*dupl;
	int		min_idx;
	int		max_idx;
	int		new;

	dupl = ft_stack_duplicate(stack);
	stack_sort(&dupl);
	if (status)
	{
		min_idx = ft_stack_find(dupl, (*interval)->data);
		max_idx = ft_stack_find(dupl, (*interval)->next->data);
		new = ft_stack_get(dupl, ((max_idx - min_idx) / 2 + min_idx + 3));
	}
	else
		new = ft_stack_get(dupl, ft_stack_size(dupl) / 2);
	ft_stack_add_begin(interval, ft_stack_new_node(new));
	stack_sort(interval);
	ft_stack_clear(&dupl);
}

int	get_first(t_stack *stack_a, t_stack *interval)
{
	int	first;
	int	max;
	int	min;

	min = interval->data;
	max = interval->next->data;
	first = 0;
	while (stack_a)
	{
		if (stack_a->data >= min && stack_a->data <= max)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (first);
}

int	get_next(t_stack *stack_a, t_stack **interval)
{
	t_stack	*dupl;
	int		pos;
	int		min;

	dupl = ft_stack_duplicate(stack_a);
	stack_sort(&dupl);
	pos = ft_stack_find(dupl, (*interval)->next->data);
	min = ft_stack_get(dupl, pos);
	if (min == ft_stack_last(dupl)->data)
	{
		ft_stack_clear(&dupl);
		return (min);
	}
	else
		min = ft_stack_get(dupl, pos + 1);
	ft_stack_clear(&dupl);
	return (min);
}
