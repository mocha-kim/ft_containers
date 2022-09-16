/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_t_1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:28:52 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/16 17:24:48 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_test.hpp"

void v_constructor()
{
	std::cout << "--------------- Constructor --------------\n";

	// default constructor
	{
		std::vector<int> v1;
		ft::vector<int> v2;

		std::cout << "> constructor(default): ";
		ite_print_compare(v1, v2);
	}

	// size constructor
	{
		std::vector<int> v1(42);
		ft::vector<int> v2(42);

		std::cout << "> constructor(size): ";
		ite_print_compare(v1, v2);
	}

	// size, value constructor
	{
		std::vector<int> v1(42, 2);
		ft::vector<int> v2(42, 2);

		std::cout << "> constructor(size, value): ";
		ite_print_compare(v1, v2);
	}

	{
		// range constructor
        std::vector<int> tmp(5);
		for (int i = 0; i < 5; i++)
			tmp[i] = i * 7;
		std::vector<int> v1(tmp.begin(), tmp.end());
		ft::vector<int> v2(tmp.begin(), tmp.end());

		std::cout << "> constructor(range): ";
		ite_print_compare(v1, v2);

		// copy constructor
		v1.push_back(49);
		v2.push_back(49);
		std::vector<int> v3(v1);
		ft::vector<int> v4(v2);

		std::cout << "> constructor(size, value): ";
		ite_print_compare(v3, v4);
	}
}

void v_assign_operator()
{
	std::cout << "------------- Assign Operator ------------\n";

	std::vector<int> tmp(5);
	for (int i = 0; i < 5; i++)
		tmp[i] = i * 7;
	std::vector<int> v1(tmp.begin(), tmp.end());
	ft::vector<int> v2(tmp.begin(), tmp.end());

	std::vector<int> v3 = v1;
	ft::vector<int> v4 = v2;

	std::cout << "> operator=: ";
	ite_print_compare(v3, v4);
}
