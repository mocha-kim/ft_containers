/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_t_1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:22:17 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/19 14:39:32 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_test.hpp"

void s_constructor()
{
	std::cout << "--------------- Constructor --------------\n";

	// default constructor
	{
		std::stack<int> s1;
		ft::stack<int> s2;

		std::cout << "> constructor(default): ";
		st_print_compare(s1, s2);
	}

	// size constructor
	{
		std::stack<int> s1;
		ft::stack<int> s2;
		for (int i = 0; i < 42; i++)
		{
			s1.push(0);
			s2.push(0);
		}

		std::cout << "> constructor(size): ";
		st_print_compare(s1, s2);
	}

	// size, salue constructor
	{
		std::stack<int> s1;
		ft::stack<int> s2;
		for (int i = 0; i < 2; i++)
		{
			s1.push(42);
			s2.push(42);
		}

		std::cout << "> constructor(size, salue): ";
		st_print_compare(s1, s2);
	}

	{
		// range constructor
		std::stack<int> s1;
		ft::stack<int> s2;
		for (int i = 0; i < 5; i++)
		{
			s1.push(i * 7);
			s2.push(i * 7);
		}

		std::cout << "> constructor(range): ";
		st_print_compare(s1, s2);

		// copy constructor
		s1.push(49);
		s2.push(49);
		std::stack<int> s3(s1);
		ft::stack<int> s4(s2);

		std::cout << "> constructor(size, salue): ";
		st_print_compare(s3, s4);
	}
}

void s_operators()
{
	std::cout << "---------------- Operators ---------------\n";

	std::stack<int> s1;
	ft::stack<int> s2;
	for (int i = 0; i < 5; i++)
	{
		s1.push(i * 7);
		s2.push(i * 7);
	}

	std::cout << "> operator=: ";
	{
		std::stack<int> s3 = s1;
		ft::stack<int> s4 = s2;
		st_print_compare(s3, s4);
	}

	std::stack<int> s3;
	ft::stack<int> s4;
	for (int i = 0; i < 7; i++)
	{
		s3.push(0);
		s4.push(0);
	}
	std::stack<int> s5(s1);
	s5.push(100);
	ft::stack<int> s6(s2);
	s6.push(100);
	std::stack<int> s7;
	ft::stack<int> s8;
	for (int i = 0; i < 3; i++)
	{
		s7.push(42);
		s8.push(42);
	}

	std::cout << "> operator==: ";
	{
		print_compare(s1 == s3, s2 == s4, false);
		std::cout << " ";

		print_compare(s7 == s3, s8 == s4, false);
		std::cout << " ";

		print_compare(s1 == s5, s2 == s6, false);
		std::cout << " ";
		
		print_compare(s1 == s7, s2 == s8, false);
		std::cout << "\n";
	}

	std::cout << "> operator!=: ";
	{
		print_compare(s1 != s3, s2 != s4, false);
		std::cout << " ";

		print_compare(s7 != s3, s8 != s4, false);
		std::cout << " ";

		print_compare(s1 != s5, s2 != s6, false);
		std::cout << " ";
		
		print_compare(s1 != s7, s2 != s8, false);
		std::cout << "\n";
	}

	std::cout << "> operator<: ";
	{
		print_compare(s1 < s3, s2 < s4, false);
		std::cout << " ";

		print_compare(s7 < s3, s8 < s4, false);
		std::cout << " ";

		print_compare(s1 < s5, s2 < s6, false);
		std::cout << " ";
		
		print_compare(s1 < s7, s2 < s8, false);
		std::cout << "\n";
	}

	std::cout << "> operator<=: ";
	{
		print_compare(s1 <= s3, s2 <= s4, false);
		std::cout << " ";

		print_compare(s7 <= s3, s8 <= s4, false);
		std::cout << " ";

		print_compare(s1 <= s5, s2 <= s6, false);
		std::cout << " ";
		
		print_compare(s1 <= s7, s2 <= s8, false);
		std::cout << "\n";
	}

	std::cout << "> operator>: ";
	{
		print_compare(s1 > s3, s2 > s4, false);
		std::cout << " ";

		print_compare(s7 > s3, s8 > s4, false);
		std::cout << " ";

		print_compare(s1 > s5, s2 > s6, false);
		std::cout << " ";
		
		print_compare(s1 > s7, s2 > s8, false);
		std::cout << "\n";
	}

	std::cout << "> operator>=: ";
	{
		print_compare(s1 >= s3, s2 >= s4, false);
		std::cout << " ";

		print_compare(s7 >= s3, s8 >= s4, false);
		std::cout << " ";

		print_compare(s1 >= s5, s2 >= s6, false);
		std::cout << " ";
		
		print_compare(s1 >= s7, s2 >= s8, false);
		std::cout << "\n";
	}
}