/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:27:37 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/16 18:40:53 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_TEST
#define _VECTOR_TEST

#include <vector>
#include "../../includes/vector.hpp"

#include "../test.hpp"

/* v_t_1 */

void v_constructor();
void v_assign_operator();

/* v_t_2 */

void v_iterator();
void v_size();
void v_capacity();

/* v_t_3 */

void v_access_operator();
void v_at();
void v_front();
void v_back();

/* v_t_4 */

void v_reserve();
void v_resize();
void v_assign();
void v_push_back();
void v_pop_back();

/* v_t_5 */

void v_insert();
void v_erase();
void v_clear();

/* v_t_6 */

void v_swap();
void v_operators();

#endif