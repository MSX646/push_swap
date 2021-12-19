/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:33:12 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/09 16:33:15 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_stack_getval(t_stack *stack, int pos)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (i == pos)
			return (stack->data);
		stack = stack->next;
		i++;
	}
	return (MIN_INT);
}
