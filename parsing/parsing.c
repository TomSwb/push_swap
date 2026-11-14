/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:07:52 by atardy            #+#    #+#             */
/*   Updated: 2026/10/26 20:09:27 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
GOAL : Set up the "flag" and "bench" parameters in stack_a from the leading
	flags, and find where the numbers start.
Return i - success: index of the first argument that is not a valid flag
	(numbers start there; parsing() checks them).
Return 0: there are only flags and no numbers which means nothing to sort.
*/
int	flags_parsing(int argc, char **argv, t_stack *s_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_memcmp(argv[i], "--simple", 9) == 0 && s_a->flag == 0)
			s_a->flag = 1;
		else if (ft_memcmp(argv[i], "--medium", 9) == 0 && s_a->flag == 0)
			s_a->flag = 2;
		else if (ft_memcmp(argv[i], "--complex", 10) == 0 && s_a->flag == 0)
			s_a->flag = 3;
		else if (ft_memcmp(argv[i], "--adaptive", 11) == 0 && s_a->flag == 0)
			s_a->flag = 4;
		else if (ft_memcmp(argv[i], "--bench", 8) == 0 && s_a->bench == 0)
			s_a->bench = 1;
		else
			return (i);
		i++;
	}
	return (0);
}

/*
GOAL : take all the ints in arguments and allocate a t_value struct per int
Return 1 : if an error occured during parsing
Return 0 : if everything went fine. 
*/
int	parsing(int start, char **argv, t_stack *stack_a)
{
	argv += start;
	while (*argv)
	{
		if (stack_from_arg(*argv, stack_a))
			return (1);
		argv++;
	}
	return (0);
}

/*
GOAL : Split one argument on spaces and add one node per number to stack_a
	(works for a single number or a string of numbers).
Return 1 : if the argument is empty or only spaces, a value is not a valid
	int or a malloc failed. //Return 1 : if the argument is empty or only spaces
Return 0 : if everything went fine.
*/
int	stack_from_arg(char *arg, t_stack *stack_a)
{
	char	**int_lst;
	int		i;
	t_value	*node;

	i = -1;
	int_lst = ft_split(arg, ' ');
	if (!int_lst)
		return (1);
	if (!int_lst[0])
		return (freeturn(int_lst));
	while (int_lst[++i])
	{
		if (check_int(int_lst[i]))
			return (freeturn (int_lst));
		stack_a->init_size++;
		node = lstnew(int_lst[i], stack_a->init_size);
		if (!node)
			return (freeturn (int_lst));
		if (stack_a->top == NULL)
			stack_a->top = node;
		else
			lstadd(stack_a, node);
	}
	freeturn (int_lst);
	return (0);
}
