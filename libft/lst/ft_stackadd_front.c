/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_begin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:34:04 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/09 16:34:07 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_stack_add_begin(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	temp = *stack;
	if (temp)
	{
		new->next = temp;
		temp->prev = new;
	}
	*stack = new;
}
