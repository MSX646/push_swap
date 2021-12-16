/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:28:48 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/09 14:28:49 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *constant, t_stack *support, char *msg)
{
	ft_swap(&(constant->data), &(constant->next->data));
	if (support)
		ft_swap(&(support->data), &(support->next->data));
	ft_putstr_fd(msg, 1);
}

void	push(t_stack **from_stack, t_stack **to_stack, char *msg)
{
	if (!(*from_stack))
		return ;
	ft_stack_add_begin(to_stack, ft_stack_new_node((*from_stack)->data));
	ft_stack_remove(from_stack);
	ft_putstr_fd(msg, 1);
}

void	rotate(t_stack **constant, t_stack **support, char *msg)
{
	int	data;

	data = ft_stack_return_first(*constant)->data;
	ft_stack_remove(constant);
	ft_stack_add_to_end(constant, ft_stack_new_node(data));
	if (support)
	{
		data = ft_stack_return_first(*support)->data;
		ft_stack_remove(support);
		ft_stack_add_to_end(support, ft_stack_new_node(data));
	}
	ft_putstr_fd(msg, 1);
}

void	rrotate(t_stack **constant,
			t_stack **support,
			char *msg)
{
	int		data;
	t_stack	*last_node;

	last_node = ft_stack_last(*constant);
	data = last_node->data;
	ft_stack_remove(&last_node);
	ft_stack_add_begin(constant, ft_stack_new_node(data));
	if (support)
	{
		last_node = ft_stack_last(*support);
		data = last_node->data;
		ft_stack_remove(&last_node);
		ft_stack_add_begin(support, ft_stack_new_node(data));
	}
	ft_putstr_fd(msg, 1);
}
