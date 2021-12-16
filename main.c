/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:28:28 by kezekiel          #+#    #+#             */
/*   Updated: 2021/12/09 14:28:35 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack(char **argv, t_stack **stack_a)
{
	int			i;
	long int	data;
	t_stack		*new_node;

	i = 0;
	while (argv[i])
	{
		if (!ft_str_isnumeric(argv[i]))
			clean_exit(*stack_a, 0, 0);
		data = ft_atoi(argv[i]);
		if (data > MAX_INT || data < MIN_INT)
			clean_exit(*stack_a, 0, 0);
		new_node = ft_stack_new_node(data);
		if (!new_node)
			clean_exit(*stack_a, 0, 0);
		ft_stack_add_to_end(stack_a, new_node);
		i++;
	}
	if (ft_stack_duplicate_int(*stack_a))
		clean_exit(*stack_a, 0, 0);
}

void	clean_exit(t_stack *stack_a, t_stack *stack_b, int status)
{
	if (stack_a)
		ft_stack_clear(&stack_a);
	if (stack_b)
		ft_stack_clear(&stack_b);
	if (!status)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit(1);
	stack_a = 0;
	stack_b = 0;
	set_stack(&argv[1], &stack_a);
	if (!ft_stack_is_sorted(stack_a))
		sorting(&stack_a, &stack_b);
	clean_exit(stack_a, stack_b, 1);
	return (0);
}
