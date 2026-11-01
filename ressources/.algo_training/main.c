/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomswb <tomswb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:19:37 by tomswb            #+#    #+#             */
/*   Updated: 2026/10/09 08:49:01 by tomswb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_training.h"

int main(void)
{
//-- test O(n2) --//
	bs_test();
	css_test();
	is_test();
	slct_test();
	shell_test();
//-- test O(n log n) --//
	merge_test();
	quick_test();
//-- test O(nk) --//
	radix_test();
}
