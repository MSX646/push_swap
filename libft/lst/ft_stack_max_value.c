/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_max_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:32:18 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/09 16:32:19 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_stack_max_value(t_stack *stack_a)
{
	int	max_value;

	max_value = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data > max_value)
			max_value = stack_a->data;
		stack_a = stack_a->next;
	}
	return (max_value);
}
