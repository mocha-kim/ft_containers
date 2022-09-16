/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:27:37 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/16 19:20:12 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_TEST
#define _VECTOR_TEST

#include <vector>
#include "../../includes/vector.hpp"

#include "../test.hpp"

/* v_t_1 */

void v_constructor();
void v_operators();

/* v_t_2 */

void v_iterator();
void v_size();
void v_capacity();

/* v_t_3 */

void v_access();
void v_assign();
void v_push_pop();

/* v_t_4 */

void v_insert();
void v_erase();
void v_clear();
void v_swap();

#endif