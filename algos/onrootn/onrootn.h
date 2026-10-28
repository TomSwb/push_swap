/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 13:36:08 by atardy            #+#    #+#             */
/*   Updated: 2026/10/28 13:36:08 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONROOTN_H
# define ONROOTN_H

// === Library === //

// push_swap.h
# include "../../push_swap.h"
# include "../onlogn/onlogn.h"

// === Struct === //

typedef struct	s_sensor
{
	t_value *node;
	int		n_buc; //
	int		pos_malus; // le coût pour traiter celui-ci avant les autres 
	int		bucket; // rang / n_bucket
	int		r; // forcément positif
	int		rr; // forcément négatif
	int		cost; // calculé en fonction de la position dans a et des couts de rota dans b
	int		winner;
}				t_sensor;

// === Functions === //

// onrootn.c
void	bucket_sort(t_stack *stack_a, t_stack *stack_b);

// onrootn_utils.c
int		find_nxt_root(int size);
int		pos_mal(int i);
int 	rk_to_buc(t_value *val, t_sensor *snr);

// onrootn_sensor.c
void	dispatch(t_stack *s_a, t_stack *s_b, t_sensor **snr);
void	sense_five(t_stack *s_a, t_stack *s_b, t_sensor **snr);
int		set_winner(t_sensor **snr, t_stack *s_b);
void	init_sensor(t_value *value_a, t_stack *s_b, t_sensor *snr, int index);
void	new_finding(t_stack *s_b, t_sensor *snr);

// onrootn_sensor_utils.c
int 	is_only_0(t_stack *s_a, t_sensor *snr);
void	sort_small(t_stack *s_a, t_stack *s_b, t_sensor *snr);
void	edge_cases(t_stack *s_a, t_stack *s_b, t_sensor **snr);
void	cost_adjust (t_sensor **snr);
void	cost_rota(t_stack *s_b, t_sensor *snr);

// onrootn_moving_a.c
void	win_to_top(t_stack *s_a, t_stack *s_b, t_sensor **snr);
void	win_to_top_2(t_stack *s_a, t_stack *s_b, t_sensor **snr);
void	moving_back(t_stack *s_a, t_stack *s_b, t_sensor **snr);
void	rotating_b (t_stack *s_a, t_stack *s_b, t_sensor *snr);

// TEST ONLY
void	print_buckets(t_stack *stack, t_sensor *snr, int nb_to_print);
#endif