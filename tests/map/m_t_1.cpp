/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_t_1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:41:05 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/19 19:28:09 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_test.hpp"

void m_constructor()
{
std::cout << "--------------- Constructor --------------\n";

	// default constructor
	{
		std::map<int, int> m1;
		ft::map<int, int> m2;

		std::cout << "> constructor(default): ";
		map_print_compare(m1, m2);
	}

	{
		// copy constructor
		std::map<int, int> m1;
		ft::map<int, int> m2;
		for (int i = 0; i < 5; i++)
		{
			m1[i] = i * 7;
			m2[i] = i * 7;
		}

		std::map<int, int> m3(m1);
		ft::map<int, int> m4(m2);

		std::cout << "> constructor(size, malue): ";
		map_print_compare(m3, m4);
	}
}

void m_operators()
{std::cout << "---------------- Operators ---------------\n";

	std::map<int, int> m1;
	ft::map<int, int> m2;
		for (int i = 0; i < 5; i++)
		{
			m1[i] = i * 7;
			m2[i] = i * 7;
		}

	std::cout << "> operator=: ";
	{
		std::map<int, int> m3 = m1;
		ft::map<int, int> m4 = m2;
		map_print_compare(m3, m4);
	}

	std::cout << "> operator[]: ";
	{
		print_compare(m1[0], m2[0], false);
		std::cout << " ";
		
		print_compare(m1[3], m2[3], false);
		std::cout << "\n";
	}

	std::map<int, int> m3;
	ft::map<int, int> m4;
	std::map<int, int> m5(m1);
	m5.insert(std::make_pair(100, -1));
	ft::map<int, int> m6(m2);
	m6.insert(ft::make_pair(100, -1));
	std::map<int, int> m7 = m3;
	m7.insert(std::make_pair(1, 10));
	ft::map<int, int> m8 = m4;
	m8.insert(ft::make_pair(1, 10));

	std::cout << "> operator==: ";
	{
		print_compare(m1 == m3, m2 == m4, false);
		std::cout << " ";

		print_compare(m7 == m3, m8 == m4, false);
		std::cout << " ";

		print_compare(m1 == m5, m2 == m6, false);
		std::cout << " ";
		
		print_compare(m1 == m7, m2 == m8, false);
		std::cout << "\n";
	}

	std::cout << "> operator!=: ";
	{
		print_compare(m1 != m3, m2 != m4, false);
		std::cout << " ";

		print_compare(m7 != m3, m8 != m4, false);
		std::cout << " ";

		print_compare(m1 != m5, m2 != m6, false);
		std::cout << " ";
		
		print_compare(m1 != m7, m2 != m8, false);
		std::cout << "\n";
	}

	std::cout << "> operator<: ";
	{
		print_compare(m1 < m3, m2 < m4, false);
		std::cout << " ";

		print_compare(m7 < m3, m8 < m4, false);
		std::cout << " ";

		print_compare(m1 < m5, m2 < m6, false);
		std::cout << " ";
		
		print_compare(m1 < m7, m2 < m8, false);
		std::cout << "\n";
	}

	std::cout << "> operator<=: ";
	{
		print_compare(m1 <= m3, m2 <= m4, false);
		std::cout << " ";

		print_compare(m7 <= m3, m8 <= m4, false);
		std::cout << " ";

		print_compare(m1 <= m5, m2 <= m6, false);
		std::cout << " ";
		
		print_compare(m1 <= m7, m2 <= m8, false);
		std::cout << "\n";
	}

	std::cout << "> operator>: ";
	{
		print_compare(m1 > m3, m2 > m4, false);
		std::cout << " ";

		print_compare(m7 > m3, m8 > m4, false);
		std::cout << " ";

		print_compare(m1 > m5, m2 > m6, false);
		std::cout << " ";
		
		print_compare(m1 > m7, m2 > m8, false);
		std::cout << "\n";
	}

	std::cout << "> operator>=: ";
	{
		print_compare(m1 >= m3, m2 >= m4, false);
		std::cout << " ";

		print_compare(m7 >= m3, m8 >= m4, false);
		std::cout << " ";

		print_compare(m1 >= m5, m2 >= m6, false);
		std::cout << " ";
		
		print_compare(m1 >= m7, m2 >= m8, false);
		std::cout << "\n";
	}
}