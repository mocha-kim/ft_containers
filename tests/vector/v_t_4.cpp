/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_t_4.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:23:55 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/16 19:40:04 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_test.hpp"

void v_insert()
{
	std::cout << "----------------- Insert -----------------\n";

	std::cout << "> insert(value): ";
	{
		std::vector<int> v1(2, 0);
		ft::vector<int> v2(2, 0);

		v1.insert(v1.begin(), 42);
		v2.insert(v2.begin(), 42);
		ite_print_compare(v1, v2, false);
		std::cout << " ";

		v1.insert(v1.begin() + 1, 21);
		v2.insert(v2.begin() + 1, 21);
		ite_print_compare(v1, v2, false);
		std::cout << "\n";
	}
	
	std::cout << "> insert(fill): ";
	{
		std::vector<int> v1(2, 0);
		ft::vector<int> v2(2, 0);

		v1.insert(v1.begin(), 2, 42);
		v2.insert(v2.begin(), 2, 42);
		ite_print_compare(v1, v2, false);
		std::cout << " ";

		v1.insert(v1.begin() + 1, 3, 21);
		v2.insert(v2.begin() + 1, 3, 21);
		ite_print_compare(v1, v2, false);
		std::cout << "\n";
	}

	std::cout << "> insert(range): ";
	{
		std::vector<int> tmp(5);
		for (int i = 0; i < 5; i++)
			tmp[i] = i * 7;

		std::vector<int> v1(2, 0);
		ft::vector<int> v2(2, 0);

		v1.insert(v1.begin() + 1, tmp.begin(), tmp.end());
		v2.insert(v2.begin() + 1, tmp.begin(), tmp.end());
		ite_print_compare(v1, v2, false);
		std::cout << " ";

		v1.insert(v1.begin() + 3, tmp.begin(), tmp.end() - 2);
		v2.insert(v2.begin() + 3, tmp.begin(), tmp.end() - 2);
		ite_print_compare(v1, v2, false);
		std::cout << "\n";
	}
}

void v_erase()
{
	std::cout << "------------------ Erase -----------------\n";

	std::cout << "> erase(position): ";
	{
		std::vector<int> v1(10, 42);
		ft::vector<int> v2(10, 42);

		v1.erase(v1.begin());
		v2.erase(v2.begin());
		ite_print_compare(v1, v2, false);
		std::cout << " ";

		v1.erase(v1.begin() + 3);
		v2.erase(v2.begin() + 3);
		ite_print_compare(v1, v2, false);
		std::cout << "\n";
	}

	std::cout << "> erase(range): ";
	{
		std::vector<int> v1(10, 42);
		ft::vector<int> v2(10, 42);

		v1.erase(v1.begin(), v1.begin() + 1);
		v2.erase(v2.begin(), v2.begin() + 1);
		ite_print_compare(v1, v2, false);
		std::cout << " ";

		v1.erase(v1.begin(), v1.end());
		v2.erase(v2.begin(), v2.end());
		ite_print_compare(v1, v2, false);
		std::cout << "\n";
	}
}

void v_clear()
{
	std::cout << "------------------ Clear -----------------\n";

	std::cout << "> clear: ";
	std::vector<int> v1(10, 42);
	ft::vector<int> v2(10, 42);

	v1.clear();
	v2.clear();
	ite_print_compare(v1, v2);
}

void v_swap()
{
	std::cout << "------------------ Swap ------------------\n";

	std::cout << "> swap: ";
	std::vector<int> v1(10, 42);
	ft::vector<int> v2(10, 42);
	std::vector<int> v3(3, 2);
	ft::vector<int> v4(3, 2);

	v1.swap(v3);
	v2.swap(v4);
	ite_print_compare(v1, v2);
}