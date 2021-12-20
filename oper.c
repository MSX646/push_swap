/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:25:11 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/20 13:25:13 by kezekiel         ###   ########.fr       */
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

void	push(t_stack **from, t_stack **to, char *msg)
{
	if (!(*from))
		return ;
	ft_stackadd_front(to, ft_stack_new_node((*from)->data));
	ft_stack_remove(from);
	ft_putstr_fd(msg, 1);
}

void	rotate(t_stack **constant, t_stack **support, char *msg)
{
	int	data;

	data = ft_stack_first(*constant)->data;
	ft_stack_remove(constant);
	ft_stackadd_back(constant, ft_stack_new_node(data));
	if (support)
	{
		data = ft_stack_first(*support)->data;
		ft_stack_remove(support);
		ft_stackadd_back(support, ft_stack_new_node(data));
	}
	ft_putstr_fd(msg, 1);
}

void	rrotate(t_stack **constant, t_stack **support, char *msg)
{
	int		data;
	t_stack	*last_node;

	last_node = ft_stack_last(*constant);
	data = last_node->data;
	ft_stack_remove(&last_node);
	ft_stackadd_front(constant, ft_stack_new_node(data));
	if (support)
	{
		last_node = ft_stack_last(*support);
		data = last_node->data;
		ft_stack_remove(&last_node);
		ft_stackadd_front(support, ft_stack_new_node(data));
	}
	ft_putstr_fd(msg, 1);
}
