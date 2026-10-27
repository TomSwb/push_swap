/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 10:48:52 by atardy            #+#    #+#             */
/*   Updated: 2026/10/27 10:49:24 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONROOTN_H
# define ONROOTN_H

// === Library === //

// push_swap.h
#include "../../push_swap.h"

// === Struct === //

typedef struct	s_sensor
{
	t_value *node;
	int		position; // -2 à +2 
	int		bucket; // rang / n_bucket
	int		n_buc; //
	int		buck_max; //
	int		r; // forcément positif
	int		rr; // forcément négatif
	int		min_cost // calculé en fonction de la position dans a et des couts de rota dans b
}				t_sensor;

// === Functions === //

// onrootn.c


// onrootn_utils.c
int	find_nxt_root(int size);

#endif