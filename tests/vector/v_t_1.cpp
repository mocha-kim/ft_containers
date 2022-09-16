/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_t_1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:28:52 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/16 19:04:26 by sunhkim          ###   ########.fr       */
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

void v_operators()
{
	std::cout << "---------------- Operators ---------------\n";

	std::vector<int> tmp(5);
	for (int i = 0; i < 5; i++)
		tmp[i] = i * 7;
	std::vector<int> v1(tmp.begin(), tmp.end());
	ft::vector<int> v2(tmp.begin(), tmp.end());

	std::cout << "> operator=: ";
	{
		std::vector<int> v3 = v1;
		ft::vector<int> v4 = v2;
		ite_print_compare(v3, v4);
	}

	std::cout << "> operator[]: ";
	{
		print_compare(v1[0], v2[0], false);
		std::cout << " ";
		
		print_compare(v1[3], v2[3], false);
		std::cout << "\n";
	}

	std::vector<int> v3(7);
	ft::vector<int> v4(7);
	std::vector<int> v5(v1);
	v5.push_back(100);
	ft::vector<int> v6(v2);
	v6.push_back(100);
	std::vector<int> v7(3, 42);
	ft::vector<int> v8(3, 42);

	std::cout << "> operator==: ";
	{
		print_compare(v1 == v3, v2 == v4, false);
		std::cout << " ";

		print_compare(v7 == v3, v8 == v4, false);
		std::cout << " ";

		print_compare(v1 == v5, v2 == v6, false);
		std::cout << " ";
		
		print_compare(v1 == v7, v2 == v8, false);
		std::cout << "\n";
	}

	std::cout << "> operator!=: ";
	{
		print_compare(v1 != v3, v2 != v4, false);
		std::cout << " ";

		print_compare(v7 != v3, v8 != v4, false);
		std::cout << " ";

		print_compare(v1 != v5, v2 != v6, false);
		std::cout << " ";
		
		print_compare(v1 != v7, v2 != v8, false);
		std::cout << "\n";
	}

	std::cout << "> operator<: ";
	{
		print_compare(v1 < v3, v2 < v4, false);
		std::cout << " ";

		print_compare(v7 < v3, v8 < v4, false);
		std::cout << " ";

		print_compare(v1 < v5, v2 < v6, false);
		std::cout << " ";
		
		print_compare(v1 < v7, v2 < v8, false);
		std::cout << "\n";
	}

	std::cout << "> operator<=: ";
	{
		print_compare(v1 <= v3, v2 <= v4, false);
		std::cout << " ";

		print_compare(v7 <= v3, v8 <= v4, false);
		std::cout << " ";

		print_compare(v1 <= v5, v2 <= v6, false);
		std::cout << " ";
		
		print_compare(v1 <= v7, v2 <= v8, false);
		std::cout << "\n";
	}

	std::cout << "> operator>: ";
	{
		print_compare(v1 > v3, v2 > v4, false);
		std::cout << " ";

		print_compare(v7 > v3, v8 > v4, false);
		std::cout << " ";

		print_compare(v1 > v5, v2 > v6, false);
		std::cout << " ";
		
		print_compare(v1 > v7, v2 > v8, false);
		std::cout << "\n";
	}

	std::cout << "> operator>=: ";
	{
		print_compare(v1 >= v3, v2 >= v4, false);
		std::cout << " ";

		print_compare(v7 >= v3, v8 >= v4, false);
		std::cout << " ";

		print_compare(v1 >= v5, v2 >= v6, false);
		std::cout << " ";
		
		print_compare(v1 >= v7, v2 >= v8, false);
		std::cout << "\n";
	}
}
