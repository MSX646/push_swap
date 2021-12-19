/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:30:08 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/09 16:34:48 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*interval;
	int		max;
	int		min;

	max = ft_stack_max(*stack_a);
	min = ft_stack_min(*stack_a);
	if (ft_stack_size(*stack_a) <= 3)
		sort3(stack_a);
	else if (ft_stack_size(*stack_a) <= 5)
		sort5(stack_a, stack_b);
	else
	{
		interval = ft_stack_new_node(min);
		ft_stackadd_back(&interval, ft_stack_new_node(max));
		sort_big(stack_a, stack_b, &interval, 0);
	}
}

void	sort3(t_stack **stack_a)
{
	int	max;
	int	min;

	max = ft_stack_max(*stack_a);
	min = ft_stack_min(*stack_a);
	while (!ft_stack_is_sorted(*stack_a))
	{
		if ((*stack_a)->data != min
			&& (*stack_a)->next->data == max)
			rrotate(stack_a, 0, "rra\n");
		else if ((*stack_a)->data == max
			&& (*stack_a)->next->data == min)
			rotate(stack_a, 0, "ra\n");
		else
			swap(*stack_a, 0, "sa\n");
	}
}

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_a) > 3)
		push_min(stack_a, stack_b);
	sort3(stack_a);
	while (ft_stack_size(*stack_b))
		push(stack_b, stack_a, "pa\n");
}

void	sort_big(t_stack **stack_a, t_stack **stack_b,
								t_stack **interval, int i)
{
	if (ft_stack_size(*interval) == 1)
	{
		ft_stack_clear(interval);
		return ;
	}
	if (ft_stack_size(*interval) == 2
		&& count_between(*stack_a, *interval) >= MAX_SIZE)
		get_limit(interval, *stack_a, 1);
	if (!ft_stack_size(*stack_b))
	{
		split_stack(stack_a, stack_b, *interval);
		rotate_until_sorted(stack_a, *interval);
	}
	if (ft_stack_size(*stack_b) >= MAX_SIZE)
		merge_halfs(stack_a, stack_b, *interval);
	else
	{
		merge_sort_a(stack_a, stack_b, *interval);
		ft_stack_remove(interval);
	}
	sort_big(stack_a, stack_b, interval, ++i);
}
