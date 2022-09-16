/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_t_2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:01:26 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/16 18:50:00 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_test.hpp"

void v_iterator()
{
	std::cout << "---------------- Iterator ----------------\n";

	std::vector<int> tmp(5);
	for (int i = 0; i < 5; i++)
		tmp[i] = i * 7;
	std::vector<int> v1(tmp.begin(), tmp.end());
	ft::vector<int> v2(tmp.begin(), tmp.end());

	// begin
	{
		std::vector<int>::iterator it1 = v1.begin();
		ft::vector<int>::iterator it2 = v2.begin();

		std::cout << "> begin: ";
		print_compare(*it1, *it1, false);
		std::cout << " ";

		it1++;
		it2++;
		print_compare(*it1, *it1, false);
		std::cout << " ";
		
		print_compare(*(it1 + 2), *(it1 + 2), false);
		std::cout << "\n";
	}

	// end
	{
		std::vector<int>::iterator it1 = v1.end();
		ft::vector<int>::iterator it2 = v2.end();

		std::cout << "> end: ";
		print_compare(*it1, *it1, false);
		std::cout << " ";

		it1--;
		it2--;
		print_compare(*it1, *it1, false);
		std::cout << " ";
		
		
		print_compare(*(it1 - 2), *(it1 - 2), false);
		std::cout << "\n";
	}

	// rbegin
	{
		std::vector<int>::reverse_iterator it1 = v1.rbegin();
		ft::vector<int>::reverse_iterator it2 = v2.rbegin();

		std::cout << "> rbegin: ";
		print_compare(*it1, *it1, false);
		std::cout << " ";
		
		it1++;
		it2++;
		print_compare(*it1, *it1, false);
		std::cout << " ";

		print_compare(*(it1 + 2), *(it1 + 2), false);
		std::cout << "\n";
	}

	// rend
	{
		std::vector<int>::reverse_iterator it1 = v1.rend();
		ft::vector<int>::reverse_iterator it2 = v2.rend();

		std::cout << "> rend: ";
		print_compare(*it1, *it1, false);
		std::cout << " ";

		it1--;
		it2--;
		print_compare(*it1, *it1, false);
		std::cout << " ";

		print_compare(*(it1 - 2), *(it1 - 2), false);
		std::cout << "\n";
	}

	// const iterator
	{
		std::vector<int>::const_iterator it1 = v1.begin();
		ft::vector<int>::const_iterator it2 = v2.begin();

		std::cout << "> const iterator: ";
		print_compare(*it1, *it1, false);
		std::cout << " ";

		std::vector<int>::const_reverse_iterator it3 = v1.rbegin();
		ft::vector<int>::const_reverse_iterator it4 = v2.rbegin();
		print_compare(*it3, *it4, false);
		std::cout << "\n";
	}
}

void v_size()
{
	std::cout << "------------------ Size ------------------\n";

	std::cout << "> empty: ";
	{
		std::vector<int> v1;
		ft::vector<int> v2;
		print_compare(v1.empty(), v2.empty(), false);
		std::cout << " ";

		v1.push_back(42);
		v2.push_back(42);
		print_compare(v1.empty(), v2.empty(), false);
		std::cout << "\n";
	}

	std::cout << "> size: ";
	{
		std::vector<int> tmp(5);
		for (int i = 0; i < 5; i++)
			tmp[i] = i * 7;
		std::vector<int> v1(tmp.begin(), tmp.end());
		ft::vector<int> v2(tmp.begin(), tmp.end());
		print_compare(v1.size(), v2.size(), false);
		std::cout << " ";

		v1.push_back(42);
		v2.push_back(42);
		print_compare(v1.size(), v2.size(), false);
		std::cout << "\n";
	}

	std::cout << "> resize: ";
	{
		std::vector<int> v1;
		ft::vector<int> v2;
		print_compare(v1.size(), v2.size(), false);
		std::cout << " ";

		v1.resize(42);
		v2.resize(42);
		print_compare(v1.size(), v2.size(), false);
		std::cout << "\n";
	}
}

void v_capacity()
{
	std::cout << "---------------- Capacity ----------------\n";

	std::vector<int> v1;
	ft::vector<int> v2;

	std::cout << "> max_size: ";
	print_compare(v1.max_size(), v2.max_size());
	v1.push_back(42);
	v2.push_back(42);

	std::cout << "> capacity: ";
	print_compare(v1.capacity(), v2.capacity());

	std::cout << "> reserve: ";
	{
		v1.clear();
		v2.clear();
		print_compare(v1.capacity(), v2.capacity(), false);
		std::cout << " ";

		v1.reserve(42);
		v2.reserve(42);
		print_compare(v1.capacity(), v2.capacity(), false);
		std::cout << "\n";
	}
}