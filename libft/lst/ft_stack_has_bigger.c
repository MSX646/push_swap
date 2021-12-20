/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_has_bigger.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:28:54 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/20 13:28:55 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_stack_has_bigger(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->data > val)
			return (1);
		stack = stack->next;
	}
	return (0);
}
