/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:31:18 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/20 13:31:19 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_stackadd_front(t_stack **stack, t_stack *new)
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
