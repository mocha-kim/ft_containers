/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:26:28 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/16 18:54:03 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector/vector_test.hpp"

int vector_test()
{
	v_constructor();
	v_operators();
	v_iterator();
	v_size();
	v_capacity();

	// v_at();
	// v_front();
	// v_back();

	// v_assign();
	// v_push_back();
	// v_pop_back();
	// v_insert();
	// v_erase();
	// v_clear();
	// v_swap();
	return 0;
}