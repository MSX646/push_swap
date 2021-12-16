/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_min_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:32:06 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/09 16:32:07 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_stack_min_value(t_stack *stack_a)
{
	int	min_value;

	min_value = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data < min_value)
			min_value = stack_a->data;
		stack_a = stack_a->next;
	}
	return (min_value);
}
