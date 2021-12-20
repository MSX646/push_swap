/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:30:42 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/20 13:31:04 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_sort(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	if (!first || !first->next)
		return ;
	second = ft_stack_split(first);
	stack_sort(&first);
	stack_sort(&second);
	*stack = merge_sort(first, second);
}

t_stack	*merge_sort(t_stack *first, t_stack *second)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (first->data < second->data)
	{
		first->next = merge_sort(first->next, second);
		first->next->prev = first;
		first->prev = 0;
		return (first);
	}
	else
	{
		second->next = merge_sort(first, second->next);
		second->next->prev = second;
		second->prev = 0;
		return (second);
	}
}

t_stack	*ft_stack_split(t_stack	*head)
{
	t_stack	*slow;
	t_stack	*fast;
	t_stack	*temp;

	slow = head;
	fast = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	temp = slow->next;
	slow->next = 0;
	return (temp);
}
