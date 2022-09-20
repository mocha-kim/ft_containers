/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_t_2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:33:28 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/20 18:33:16 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_test.hpp"

void m_iterator()
{
	std::cout << "---------------- Iterator ----------------\n";
	
	std::map<int, int> m1;
	ft::map<int, int> m2;
	for (int i = 0; i < 5; i++)
	{
		m1[i] = i * 7;
		m2[i] = i * 7;
	}

	std::cout << "> begin: ";
	{
		std::map<int, int>::iterator std_it = m1.begin();
		ft::map<int, int>::iterator ft_it = m2.begin();
		
		pair_print_compare(*std_it, *ft_it, false);
		std::cout << " ";

		std_it++;
		ft_it++;
		pair_print_compare(*std_it, *ft_it);
	}

	std::cout << "> end: ";
	{
		std::map<int, int>::iterator std_it = m1.end();
		ft::map<int, int>::iterator ft_it = m2.end();
		
		std_it--;
		ft_it--;
		pair_print_compare(*std_it, *ft_it, false);
		std::cout << " ";

		std_it--;
		ft_it--;
		pair_print_compare(*std_it, *ft_it);
	}

	std::cout << "> rbegin: ";
	{
		std::map<int, int>::reverse_iterator std_it = m1.rbegin();
		ft::map<int, int>::reverse_iterator ft_it = m2.rbegin();

		std_it++;
		ft_it++;
		pair_print_compare(*std_it, *ft_it, false);
		std::cout << " ";

		std_it++;
		ft_it++;
		pair_print_compare(*std_it, *ft_it);
	}

	std::cout << "> rend: ";
	{
		std::map<int, int>::reverse_iterator std_it = m1.rend();
		ft::map<int, int>::reverse_iterator ft_it = m2.rend();
		
		std_it--;
		ft_it--;
		pair_print_compare(*std_it, *ft_it, false);
		std::cout << " ";

		std_it--;
		ft_it--;
		pair_print_compare(*std_it, *ft_it);
	}
}

void m_size()
{
	std::cout << "------------------ Size ------------------\n";

	std::cout << "> empty: ";
	{
		std::map<int, int> m1;
		ft::map<int, int> m2;
		print_compare(m1.empty(), m2.empty(), false);
		std::cout << " ";

		m1[42] = 7;
		m2[42] = 7;
		print_compare(m1.empty(), m2.empty());
	}

	std::cout << "> size: ";
	{
		std::map<int, int> m1;
		ft::map<int, int> m2;
		for (int i = 0; i < 5; i++)
		{
			m1[i] = i * 7;
			m2[i] = i * 7;
		}
		print_compare(m1.size(), m2.size(), false);
		std::cout << " ";

		m1[42] = 7;
		m2[42] = 7;
		print_compare(m1.size(), m2.size());
	}
}

void m_capacity()
{
	std::cout << "---------------- Capacity ----------------\n";

	std::map<int, int> m1;
	ft::map<int, int> m2;

	std::cout << "> max_size: ";
	print_compare(m1.max_size(), m2.max_size(), false);
	std::cout << " ";

	m1[42] = 7;
	m2[42] = 7;
	print_compare(m1.size(), m2.size());
}