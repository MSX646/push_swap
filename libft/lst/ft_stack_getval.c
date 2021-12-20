/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_getval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:28:47 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/20 13:28:48 by kezekiel         ###   ########.fr       */
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
