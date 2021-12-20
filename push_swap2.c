/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:25:28 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/20 13:25:29 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack(t_stack **stack_a, t_stack **stack_b, t_stack *interval)
{
	int	size;
	int	first;

	size = count_between(*stack_a, interval);
	while (ft_stack_size(*stack_b) < size)
	{
		first = get_first(*stack_a, interval);
		while (first--)
			rotate(stack_a, 0, "ra\n");
		push(stack_a, stack_b, "pb\n");
	}
}

void	merge_halfs(t_stack **stack_a, t_stack **stack_b, t_stack *interval)
{
	get_limit(&interval, *stack_b, 0);
	while (ft_stack_has_bigger(*stack_b, interval->next->data))
	{
		if ((*stack_b)->data == ft_stack_min(*stack_b))
		{
			push(stack_b, stack_a, "pa\n");
			if ((*stack_b)->data != ft_stack_min(*stack_b)
				&& (*stack_b)->data <= interval->next->data)
				rotate(stack_a, stack_b, "rr\n");
			else
				rotate(stack_a, 0, "ra\n");
		}
		else if ((*stack_b)->data > interval->next->data)
			push(stack_b, stack_a, "pa\n");
		else
			rotate(stack_b, 0, "rb\n");
	}
}

void	merge_sort_a(t_stack **stack_a, t_stack **stack_b, t_stack *interval)
{
	t_stack	*dupl;

	dupl = ft_stack_duplicate(*stack_b);
	stack_sort(&dupl);
	while (ft_stack_size(*stack_b))
	{
		if ((*stack_b)->data == dupl->data)
		{
			push(stack_b, stack_a, "pa\n");
			dupl = dupl->next;
			if (ft_stack_size(*stack_b) && (*stack_b)->data != dupl->data
				&& (*stack_b)->data != ft_stack_max(*stack_b))
				rotate(stack_a, stack_b, "rr\n");
			else
				rotate(stack_a, 0, "ra\n");
		}
		else if ((*stack_b)->data == ft_stack_max(*stack_b))
			push(stack_b, stack_a, "pa\n");
		else
			rotate(stack_b, 0, "rb\n");
	}
	while (ft_stack_last(*stack_a)->data != interval->next->data)
		rotate(stack_a, 0, "ra\n");
	interval->next->data = get_next(*stack_a, &interval);
	ft_stack_clear(&dupl);
}

void	rotate_until_sorted(t_stack **stack_a, t_stack *interval)
{
	t_stack	*dupl;
	int		num;
	int		index;

	dupl = ft_stack_duplicate(*stack_a);
	ft_stackadd_front(&dupl, ft_stack_new_node(interval->data));
	stack_sort(&dupl);
	num = ft_stack_getval(dupl, ft_stack_find(dupl, interval->data) - 1);
	ft_stack_clear(&dupl);
	index = ft_stack_find(*stack_a, num);
	if (num == MIN_INT || index == MIN_INT)
		return ;
	if (index <= ft_stack_size(*stack_a) / 2)
		while (ft_stack_last(*stack_a)->data != num)
			rotate(stack_a, 0, "ra\n");
	else
		while (ft_stack_last(*stack_a)->data != num)
			rrotate(stack_a, 0, "rra\n");
}

int	count_between(t_stack *stack_a, t_stack *interval)
{
	t_stack	*dupl;
	int		max_idx;
	int		min_idx;

	dupl = ft_stack_duplicate(stack_a);
	stack_sort(&dupl);
	min_idx = ft_stack_find(dupl, interval->data);
	max_idx = ft_stack_find(dupl, interval->next->data);
	ft_stack_clear(&dupl);
	return (max_idx - min_idx + 1);
}
