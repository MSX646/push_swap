/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:33:21 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/09 16:33:21 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_stack_find(t_stack *stack, int val)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (val == stack->data)
			return (i);
		stack = stack->next;
		i++;
	}
	return (MIN_INT);
}
