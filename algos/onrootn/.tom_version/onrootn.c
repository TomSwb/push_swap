/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 21:48:19 by atardy            #+#    #+#             */
/*   Updated: 2026/11/02 00:05:19 by tschwab          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "structs.h"
#include "onrootn.h"

/*

*/
void	bucket_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_sensor	data;

	init_data(stack_a, &data);
	dispatch(stack_a, stack_b, &data);
	bring_back(stack_a, stack_b);
}
