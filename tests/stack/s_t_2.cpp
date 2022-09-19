/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_t_2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:50:26 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/19 14:56:32 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_test.hpp"

void s_size()
{
	std::cout << "------------------ Size ------------------\n";

	std::cout << "> empty: ";
	{
		std::stack<int> s1;
		ft::stack<int> s2;
		print_compare(s1.empty(), s2.empty(), false);
		std::cout << " ";

		s1.push(42);
		s2.push(42);
		print_compare(s1.empty(), s2.empty(), false);
		std::cout << "\n";
	}

	std::cout << "> size: ";
	{
		std::stack<int> s1;
		ft::stack<int> s2;
		for (int i = 0; i < 5; i++)
		{
			s1.push(i * 7);
			s2.push(i * 7);
		}
		print_compare(s1.size(), s2.size(), false);
		std::cout << " ";

		s1.push(42);
		s2.push(42);
		print_compare(s1.size(), s2.size(), false);
		std::cout << "\n";
	}
}

void s_top()
{
	std::cout << "----------------- Access -----------------\n";
	std::stack<int> s1;
	ft::stack<int> s2;
	for (int i = 0; i < 5; i++)
	{
		s1.push(i * 7);
		s2.push(i * 7);
	}
	std::cout << "> top: ";
	print_compare(s1.top(), s2.top(), false);
	std::cout << " ";

	s1.pop();
	s2.pop();
	print_compare(s1.top(), s2.top(), false);
	std::cout << " ";

	s1.push(3);
	s2.push(3);
	print_compare(s1.top(), s2.top(), false);
	std::cout << "\n";
}

void s_push_pop()
{
	std::cout << "--------------- Push / Pop ---------------\n";
	std::stack<int> s1;
	ft::stack<int> s2;
	
	std::cout << "> push: ";
	for (int i = 0; i < 5; i++)
	{
		s1.push(i * 7);
		s2.push(i * 7);
	}
	print_compare(s1.top(), s2.top(), false);
	std::cout << " ";

	s1.push(3);
	s2.push(3);
	print_compare(s1.top(), s2.top(), false);
	std::cout << "\n";

	std::cout << "> pop: ";
	s1.pop();
	s2.pop();
	print_compare(s1.top(), s2.top(), false);
	std::cout << " ";

	s1.pop();
	s2.pop();
	print_compare(s1.top(), s2.top(), false);
	std::cout << " ";

	s1.pop();
	s2.pop();
	print_compare(s1.top(), s2.top(), false);
	std::cout << "\n";
}