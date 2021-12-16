#include "../libft.h"

t_stack	*ft_stack_new_node(int data)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!stack)
		return (NULL);
	stack->data = data;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}
