/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:50:22 by atardy            #+#    #+#             */
/*   Updated: 2026/10/27 20:50:22 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONROOTN_H
# define ONROOTN_H

// === Library === //

// push_swap.h
#include "../../push_swap.h"
#include "../onlogn/onlogn.h"

// === Struct === //

typedef struct	s_sensor
{
	t_value *node;
	int		n_buc; //
	int		buck_max; //
	int		pos_malus; // le coût pour traiter celui-ci avant les autres 
	int		bucket; // rang / n_bucket
	int		r; // forcément positif
	int		rr; // forcément négatif
	int		cost; // calculé en fonction de la position dans a et des couts de rota dans b
	int		new;
	int		winner;
}				t_sensor;

// === Functions === //

// onrootn.c


// onrootn_utils.c
int		find_nxt_root(int size);
int		pos_mal(int i);
int 	rk_to_buc(t_value *val, t_sensor *snr);

// onrootn_sensor.c
void	dispatch(t_stack *s_a, t_stack *s_b, t_sensor **snr);
void	sense_five(t_stack *s_a, t_stack *s_b, t_sensor **snr);
int		set_winner(t_stack *s_a, t_stack *s_b, t_sensor **snr);
void	init_sensor(t_value *value_a, t_stack *s_b, t_sensor *snr);
void	new_finding(t_stack *s_b, t_sensor *snr);

// onrootn_sensor_utils.c
int 	is_only_max(t_stack *s_a, t_sensor *snr);
int		bucket_cmp(t_value *current, t_sensor *snr);
void	edge_cases(t_stack *s_a, t_stack *s_b, t_sensor **snr);
void	cost_adjust (t_stack *s_a, t_stack *s_b, t_sensor **snr);
void	cost_rota(t_stack *s_b, t_sensor *snr);

// onrootn_moving_a.c
void	win_to_top(t_stack *s_a, t_stack *s_b, t_sensor **snr);
void	win_to_top_2(t_stack *s_a, t_stack *s_b, t_sensor **snr);
void	moving_back(t_stack *s_a, t_stack *s_b, t_sensor **snr);
void	moving_back_2(t_stack *s_a, t_stack *s_b, t_sensor **snr);

#endif