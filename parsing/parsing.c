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
#include "structs.h"
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
		if (ft_isdigit(argv[i][0]) || ((argv[i][0] == '-' || argv[i][0] == '+')
		&& ft_isdigit(argv[i][1])))
			return (0);
		else if (ft_memcmp(argv[i], "--simple", 9) == 0 && s_a->flag == 0)
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
	argc--;
	argv++;
	while (*argv && argv[0][0] == '-' && argv[0][1] == '-')
	{
		argv++;
		argc--;
	}
	while (argv)
	{
		if (stack_from_arg(*argv, stack_a))
			return (1);
		argv++;
	}
	return (0);
}

/**
* @brief

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
	stack_a->init_size = i;
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
	stack_a->init_size = nb_int;
	return (0);
}
