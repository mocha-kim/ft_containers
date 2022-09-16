/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_t_1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:28:52 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/16 16:50:12 by sunhkim          ###   ########.fr       */
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
		print_value_compare(v1, v2);
	}

	// size constructor
	{
		std::vector<int> v1(42);
		ft::vector<int> v2(42);

		std::cout << "> constructor(size): ";
		print_value_compare(v1, v2);
	}

	// size, value constructor
	{
		std::vector<int> v1(42, 2);
		ft::vector<int> v2(42, 2);

		std::cout << "> constructor(size, value): ";
		print_value_compare(v1, v2);
	}

	{
		// range constructor
        int tmp[] = { 7, 14, 21, 35, 42 };
        std::vector<int>::iterator it1(&(tmp[0]));
        ft::vector<int>::iterator it2(&(tmp[0]));

		std::vector<int> v1(it1, it1 + 5);
		ft::vector<int> v2(it2, it2 + 5);

		std::cout << "> constructor(range): ";
		print_value_compare(v1, v2);

		// copy constructor
		v1.push_back(49);
		v2.push_back(49);
		std::vector<int> v3(v1);
		ft::vector<int> v4(v2);

		std::cout << "> constructor(size, value): ";
		print_value_compare(v3, v4);
	}
}

void v_assign_operator()
{
	std::cout << "------------- Assign Operator ------------\n";
	
	int tmp[] = { 7, 14, 21, 35, 42 };
	std::vector<int>::iterator it1(&(tmp[0]));
	ft::vector<int>::iterator it2(&(tmp[0]));

	std::vector<int> v1(it1, it1 + 5);
	ft::vector<int> v2(it2, it2 + 5);

	std::vector<int> v3 = v1;
	ft::vector<int> v4 = v2;

	std::cout << "> operator=: ";
	print_value_compare(v3, v4);
}
