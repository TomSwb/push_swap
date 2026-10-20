/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:13:58 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 11:14:06 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	// t_value	*checked;
	// int		id_stop = -1;
	if (argc == 1)
		return (write_error(1));
	stack_initializer(&stack_a);
	stack_initializer(&stack_b);
	if (flags_parsing(argc, argv, &stack_a))
		return (write_error(2));
	if (stack_a.flag == 0)
		stack_a.flag = 4;
	if (parsing(argc, argv, &stack_a) || check_double(&stack_a))
		return (lstclear(&stack_a, 1));
	stack_a.init_size = size_calculator(&stack_a);
	// printf ("bench = %d / flag = %d \n", stack_a.bench, stack_a.flag);
	// printf ("check doublon = %d\n",check_double(&stack_a));
	// checked = stack_a.top;
	// while(checked->id != id_stop)
	// {
	// 	id_stop = stack_a.top->id;
	// 	printf ("id %d, value %d\n", checked->id, checked->value);
	// 	checked = checked->next;
	// }
	print_list(&stack_a);
	lstclear(&stack_a, 0);
	ft_printf("lst cleared");
	return (0);
}

void	print_list(t_stack *stack_a)
{
	size_t	i;
	t_value	*temp;

	temp = stack_a->top;
	i = 0;
	while (i < stack_a->init_size)
	{
		ft_printf("%d\n", temp->value);
		temp = temp->next;
		i++;
	}
}

/*
GOAL : Write Error on std error. TEST ONLY : Can print where the error come from
	(also here to gain lines)
Return : always 1
*/
int	write_error(int n)
{
	// For test purpose
	if (n == 1)
		ft_printf("argc == 1\n");
	if (n == 2)
		ft_printf("flag parsing error or no int\n");
	if (n ==3)
		ft_printf("going through lstclear\n");
	// Real function below
	(void) n;
	ft_printf("Error\n");
	return (1);
}
