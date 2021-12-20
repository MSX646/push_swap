/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_duplicate_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:28:20 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/20 13:28:33 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_stack_duplicate_int(t_stack *stack)
{
	t_stack	*is_sorted;

	is_sorted = ft_stack_duplicate(stack);
	stack_sort(&is_sorted);
	while (is_sorted->next)
	{
		if (is_sorted->data == is_sorted->next->data)
			return (1);
		is_sorted = is_sorted->next;
	}
	ft_stack_clear(&is_sorted);
	return (0);
}
