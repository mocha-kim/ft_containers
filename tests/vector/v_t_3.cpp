/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_t_3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:06:35 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/16 19:22:23 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_test.hpp"

void v_access()
{
	std::cout << "----------------- Access -----------------\n";
	std::vector<int> tmp(5);
	for (int i = 0; i < 5; i++)
		tmp[i] = i * 7;
	std::vector<int> v1(tmp.begin(), tmp.end());
	ft::vector<int> v2(tmp.begin(), tmp.end());

	std::cout << "> at: ";
	{
		print_compare(v1.at(2), v2.at(2), false);
		std::cout << " ";

		print_compare(v1.at(0), v2.at(0), false);
		std::cout << "\n";
	}
	std::cout << "> front: ";
	{
		print_compare(v1.front(), v2.front());
	}
	std::cout << "> back: ";
	{
		print_compare(v1.back(), v2.back());
	}
}

void v_assign()
{
	std::cout << "----------------- Assign -----------------\n";
	std::vector<int> v1;
	ft::vector<int> v2;

	std::cout << "> assign(value): ";
	{
		v1.assign(3, 42);
		v2.assign(3, 42);
		ite_print_compare(v1, v2, false);
		std::cout << " ";

		v1.assign(10, 0);
		v2.assign(10, 0);
		ite_print_compare(v1, v2, false);
		std::cout << "\n";
	}

	std::cout << "> assign(range): ";
	{
		std::vector<int> tmp(5);
		for (int i = 0; i < 5; i++)
			tmp[i] = i * 7;

		v1.assign(tmp.begin(), tmp.end());
		v2.assign(tmp.begin(), tmp.end());
		ite_print_compare(v1, v2, false);
		std::cout << " ";

		tmp.clear();
		v1.assign(tmp.begin(), tmp.end());
		v2.assign(tmp.begin(), tmp.end());
		ite_print_compare(v1, v2, false);
		std::cout << "\n";
	}
}

void v_push_pop()
{
	std::cout << "--------------- Push / Pop ---------------\n";
	std::vector<int> v1(5, 0);
	ft::vector<int> v2(5, 0);

	std::cout << "> push_back: ";
	v1.push_back(42);
	v2.push_back(42);
	ite_print_compare(v1, v2);
	std::cout << "> pop_back: ";
	v1.pop_back();
	v2.pop_back();
	ite_print_compare(v1, v2);
}