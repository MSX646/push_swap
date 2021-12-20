/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:30:08 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/20 13:30:09 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_stack_remove(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = *stack;
	if (temp->next)
		temp->next->prev = temp->prev;
	if (temp->prev)
		temp->prev->next = temp->next;
	if (temp->prev)
		*stack = temp->prev;
	else
		*stack = temp->next;
	free(temp);
}
