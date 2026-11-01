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
GOAL : Set-up the "flag" and "bench" parameter in stack-a. Also check if 
	there's at least one of the 3 first args that START with a digit.
Return 0 - success: It finds only valid flags then an arg that START with a nb
Return 1 - failure: The 3 (or less if argc <3) first args are not only 
valid flags or an arg that starts with a number.
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

/**
* @brief
Splits the arguments into nodes no matter if they are given as one string,
multiple strings or simple numbers.

* @param char *arg
* @param t_stack *stack_a
* @return int
*/
int	stack_from_arg(char *arg, t_stack *stack_a)
{
	char	**int_lst;
	int		i;
	t_value	*node;

	i = 0;
	int_lst = ft_split(arg, ' ');
	if (!int_lst)
		return (1);
	while (int_lst[i])
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
		i++;
	}
	freeturn (int_lst);
	return (0);
}
