/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:58:05 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/22 15:27:37 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map/map_test.hpp"

int map_test()
{
	m_constructor();
	m_operators();
	m_iterator();
	m_size();
	m_capacity();
	m_insert();
	m_erase();
	m_clear();
	m_swap();
	m_obeservers();
	// m_access();
	// m_find();
	return 0;
}