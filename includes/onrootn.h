/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 21:48:41 by atardy            #+#    #+#             */
/*   Updated: 2026/11/01 21:48:47 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONROOTN_H
# define ONROOTN_H

// === Library === //

// push_swap.h
# include "structs.h"

// === Struct === //

typedef struct s_sensor
{
	int	chunk_size;
	int	limit;
	int	pushed;
	int	half;
	int	top_pos;
	int	bottom_pos;
}	t_sensor;

// === Functions === //

// onrootn.c
void	bucket_sort(t_stack *stack_a, t_stack *stack_b);
void	dispatch(t_stack *s_a, t_stack *s_b, t_sensor *data);
void	bring_back(t_stack *s_a, t_stack *s_b);

// onrootn_utils.c
void	init_data(t_stack *stack_a, t_sensor *data);
int		find_nxt_root(int size);
t_value	*find_closest(t_stack *stack_a, t_sensor *data);
t_value	*node_to_move(t_stack *stack_b, size_t *pos);

#endif