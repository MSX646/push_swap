/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:33:40 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/09 16:33:41 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_stack	*ft_stack_duplicate(t_stack *stack)
{
	t_stack	*dup;
	t_stack	*new_node;

	dup = 0;
	while (stack)
	{
		new_node = ft_stack_new_node(stack->data);
		if (!new_node)
		{
			ft_stack_clear(&dup);
			return (0);
		}
		ft_stackadd_back(&dup, new_node);
		stack = stack->next;
	}
	return (dup);
}
