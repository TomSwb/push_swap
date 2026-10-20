/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:00:38 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 11:01:20 by atardy           ###   ########.ch       */
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

	i = 0;
	while (++i <= 3 && i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 8) == 0 && s_a->flag == 0)
			s_a->flag = 1;
		else if (ft_strncmp(argv[i], "--medium", 8) == 0 && s_a->flag == 0)
			s_a->flag = 2;
		else if (ft_strncmp(argv[i], "--complex", 9) == 0 && s_a->flag == 0)
			s_a->flag = 3;
		else if (ft_strncmp(argv[i], "--adaptive", 10) == 0 && s_a->flag == 0)
			s_a->flag = 4;
		else if (ft_strncmp(argv[i], "--bench", 8) == 0 && s_a->bench == 0)
			s_a->bench = 1;
		else if (ft_isdigit(argv[i][0]))
			return (0);
		else
			return (1);
	}
	return (1);
}

/*
GOAL : take all the ints in arguments and allocate a t_value struct per int
Return 1 : if an error occured during parsing
Return 0 : if everything went fine. 
*/
int	parsing(int argc, char **argv, t_stack *stack_a)
{
	char	**int_lst;

	argc--;
	while (**(++argv) == '-')
		argc--;
	if (argc == 1)
	{
		int_lst = ft_split(*argv, ' ');
		if (check_int(*int_lst) > 0)
			return (freeturn (int_lst));
		stack_a->top = lstnew(int_lst[0], 1);
		if (stack_a->top == NULL)
			return (freeturn(int_lst));
		if (stack_from_split (int_lst, stack_a))
			return (freeturn(int_lst));
		return (0);
	}
	else
		return (pars_from_argv(argc, argv, stack_a));
}

/*
GOAL : Creating one node per value in the int_list (from split) by using
		lstnew and lstadd.
Return 1 : if a value doesn't pass the check_int value OR
		if a lstnew had a problem to create the structs.
Return 0 : if everything went fine. 
*/
int	stack_from_split(char **int_lst, t_stack *stack_a)
{
	int		i;
	t_value	*node;

	i = 0;
	while (int_lst[++i])
	{
		if (check_int(int_lst[i]) > 0)
			return (1);
		node = lstnew(int_lst[i], i + 1);
		if (!node)
			return (1);
		lstadd(stack_a, node);
	}
	i = -1;
	while (int_lst[++i])
	{
		free (int_lst[i]);
		int_lst[i] = NULL;
	}
	free (int_lst);
	int_lst = NULL;
	return (0);
}

/*
GOAL : Creating one node per value in the int_list (from args) by using
		lstnew and lstadd.
Return 1 : if a value doesn't pass the check_int value OR
		if a lstnew had a problem to create a struct.
Return 0 : if everything went fine. 
*/
int	pars_from_argv(int nb_int, char **int_lst, t_stack *stack_a)
{
	int		i;
	t_value	*node;

	i = 0;
	if (check_int(int_lst[0]) > 0)
		return (1);
	node = lstnew(int_lst[i], i);
	if (!node)
		return (1);
	stack_a->top = node;
	while (++i < nb_int)
	{
		if (check_int(int_lst[i]) > 0)
			return (1);
		node = lstnew(int_lst[i], i);
		if (!node)
			return (1);
		lstadd(stack_a, node);
	}
	return (0);
}
