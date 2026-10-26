/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onrootn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:01:07 by atardy            #+#    #+#             */
/*   Updated: 2026/10/26 18:01:46 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "onrootn.h"

/*
BUCKET SORT with root(n) buckets. (normal, not push_swap-style)
1. Calculate root(n)
2. Dispatch values in n bucket. Each value is in bucket[rank / root(n)]
3. Sorting each bucket with a On2 algorithm
4. Merging them back together => all values of bucket 1, then bucket 2, ...
DONE
*/

