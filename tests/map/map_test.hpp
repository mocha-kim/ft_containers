/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:59:20 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/19 15:45:39 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_TEST
#define _MAP_TEST

#include <map>
#include "../../includes/map.hpp"

#include "../test.hpp"

/* m_t_1 */

void m_constructor();
void m_operators();

/* m_t_2 */

void m_iterator();
void m_size();
void m_capacity();

/* v_t_3 */

void m_insert();
void m_erase();
void m_clear();
void m_swap();

/* v_t_4 */

void m_obeservers();
void m_access();
void m_find();

#endif