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
	t_value	*node;
	int		n_buc;
	int		pos_malus; // le coût pour traiter celui-ci avant les autres 
	int		bucket; // rang / n_bucket
	int		r; // forcément positif
	int		rr; // forcément négatif
	int		cost; // calculé en fonction de la position dans a
	//  et des couts de rota dans b
	int		winner;
	int		max_buck;
	int		min_buck;
	int		max_rank;
	int		min_rank;
}	t_sensor;

// === Functions === //

// onrootn.c
void	bucket_sort(t_stack *stack_a, t_stack *stack_b);
int		sensor_alloc(t_sensor **sensor, t_stack *s_a);

// onrootn_utils.c
int		find_nxt_root(int size);
void	freeing_snr(t_sensor **snr, int i);
int		rk_to_buc(t_value *val, t_sensor *snr);

// onrootn_sensor.c
void	dispatch(t_stack *s_a, t_stack *s_b, t_sensor **snr);

// onrootn_sensor_utils.c
int		is_only_0(t_stack *s_a, t_sensor *snr);

#endif