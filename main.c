/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 08:20:50 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 08:21:59 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main (int argc, char **argv)
{
						t_value	*checked;
						int		id_stop = -1;
	t_stack	stack_a;
	t_stack	stack_b;
	
	if (argc == 1)
		return (write_error(1));
	stack_initializer(&stack_a);
	stack_initializer(&stack_b);
	if (flags_parsing(argc, argv, &stack_a))
		return (write_error(2));
	if (stack_a.flag == 0)
		stack_a.flag = 4;
	if (parsing(argc, argv, &stack_a) || check_double(&stack_a))
		return (lstclear(&stack_a));

	
	// printf ("bench = %d / flag = %d \n", stack_a.bench, stack_a.flag);
	// printf ("check doublon = %d\n",check_double(&stack_a));
	// checked = stack_a.top;
	// while(checked->id != id_stop)
	// {
	// 	id_stop = stack_a.top->id;
	// 	printf ("id %d, value %d\n", checked->id, checked->value);
	// 	checked = checked->next;
	// }
	
	return (0);
}