/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 08:05:22 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 08:05:30 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
GOAL : Check if this int is a valid one (in int range && only digit)
Return 1 or more : if int is not valid
Return 0 or less : if int is valid
*/
int	check_int(char *content)
{
	int	i;

	i = -1;
	while (content[++i])
		if (!(ft_isdigit(content[i]) || (i == 0 && content[i] == '-')))
			return(1);
	if ((content[0] == '-' && ft_strlen(content) > 11)
		|| (content[0] != '-' && ft_strlen(content) > 10))
			return (1);
	else if ((content[0] == '-' && ft_strlen(content) < 11)
		|| (content[0] != '-' && ft_strlen(content) < 10))
			return (0);
	if (content[0] == '-')
		return (ft_strncmp(content, "-2147483648", 11));
	else if (content[0] != '-')
		return(ft_strncmp(content, "2147483647", 10));
	return (1);
}

/*
GOAL : create a new t_value struct with the content (transformed by atoi) and
	the id given as arguments
Return NULL : if a malloc failed
Return a pointer to the new struct if everything went fine
*/
t_value *lstnew(void *content, int id)
{
	t_value	*new;
	
	if (!content)
		return (NULL);
	new = malloc (sizeof(t_value));
	if (new == NULL)
		return (NULL);
	new->value = ft_atoi(content);
	new->next = NULL;
	new->prev = NULL;
	new->id = id;
	return (new);
}

/*
GOAL : add new struct in the circular linked list
Return : void
*/
void	lstadd(t_stack *head,t_value *new)
{
	t_value *last;

	if (!new || !head)
		return ;
	if (!((head->top)->next) || !((head->top)->prev))
	{
		(head->top)->next = new;
		(head->top)->prev = new;
		new->next = head->top;
		new->prev = head->top;
		return ;
	}
	last = (head->top)->prev;
	last->next = new;
	new->prev = last;
	new->next = head->top;
	(head->top)->prev = new;
}

/*
GOAL : Suppress all the structs created and write error on stderror
Return 1 : always
*/
int	lstclear(t_stack *head)
{
	t_value *current;
	t_value *next_adress;

	current = head->top;
	((head->top)->prev)->next = NULL;
	while (current)
	{
		next_adress = current->next;
		current->next = NULL;
		current->prev = NULL;
		free (current);
		current = NULL;
		current = next_adress;
	}
	return (write_error(3));
}

/*
GOAL : check all the values of stack_a for a double
Return 1 : if it finds a double
Return 0 : else
*/
int	check_double(t_stack *head)
{
	t_value	*checked;
	t_value	*read;
	int		id_stop;
	
	checked = head->top;
	id_stop = -1;
	while(checked->id != id_stop)
	{
		id_stop = head->top->id;
		read = checked->next;
		while(read != checked)
		{
			if (checked->value == read->value)
				return (1);
			read = read->next;
		}
		checked = checked->next;
	}
	return (0);
}

