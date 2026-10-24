/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:59:11 by atardy            #+#    #+#             */
/*   Updated: 2026/10/20 11:00:10 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
GOAL : Check if this int is a valid one (in int range && only digit)
Return 1 or more : if int is not valid
Return 0 or less : if int is valid
*/
int	check_int(char *content)
{
	int	i;

	i = -1;
	if (content[0] == '\0' || (content[0] == '-' && !ft_isdigit(content[1])))
		return (1);
	while (content[++i])
		if (!(ft_isdigit(content[i]) || (i == 0 && content[i] == '-')))
			return (1);
	if ((content[0] == '-' && ft_strlen(content) > 11)
		|| (content[0] != '-' && ft_strlen(content) > 10))
		return (1);
	else if ((content[0] == '-' && ft_strlen(content) < 11)
		|| (content[0] != '-' && ft_strlen(content) < 10))
		return (0);
	if (content[0] == '-')
		return (ft_strncmp(content, "-2147483648", 11));
	else if (content[0] != '-')
		return (ft_strncmp(content, "2147483647", 10));
	return (1);
}

/*
GOAL : create a new t_value struct with the content (transformed by atoi) and
	the id given as arguments
Return NULL : if a malloc failed
Return a pointer to the new struct if everything went fine
*/
t_value	*lstnew(void *content, int id)
{
	t_value	*node;

	if (!content)
		return (NULL);
	node = malloc (sizeof(t_value));
	if (node == NULL)
		return (NULL);
	node->value = ft_atoi(content);
	node->next = node;
	node->prev = node;
	node->id = id;
	node->rank = -1;
	return (node);
}

/*
GOAL : add new struct in the circular linked list
Return : void
*/
void	lstadd(t_stack *head, t_value *node)
{
	t_value	*last;

	if (!node || !head)
		return ;
	last = (head->top)->prev;
	last->next = node;
	node->prev = last;
	node->next = head->top;
	(head->top)->prev = node;
}

/*
GOAL : Suppress all the structs created and write error on stderror
Return 1 : always
In error to indicate if needing an error code or not.
*/
int	lstclear(t_stack *head, int error)
{
	t_value	*current;
	t_value	*next_adress;

	if (head->top)
	{
		current = head->top;
		((head->top)->prev)->next = NULL;
		while (current)
		{
			next_adress = current->next;
			current->next = NULL;
			current->prev = NULL;
			free (current);
			current = next_adress;
		}
		head->top = NULL;
	}
	if (error == 1)
		return (write_error(3));
	else
		return (1);
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
	while (checked->id != id_stop)
	{
		id_stop = head->top->id;
		read = checked->next;
		while (read != checked)
		{
			if (checked->value == read->value)
				return (1);
			read = read->next;
		}
		checked = checked->next;
	}
	return (0);
}
