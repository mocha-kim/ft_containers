/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_t_3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:22:56 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/22 14:31:41 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_test.hpp"
#include <vector>

void m_insert()
{
	std::cout << "----------------- Insert -----------------\n";

	std::map<std::string, int> std_m;
	ft::map<std::string, int> ft_m;
	std::cout << "> insert(value): ";
	{
		std_m.insert(std::make_pair("test", 42));
		ft_m.insert(ft::make_pair("test", 42));
		map_print_compare(std_m, ft_m, false);
		std::cout << " ";

		std_m.insert(std::make_pair("42", 0));
		ft_m.insert(ft::make_pair("42", 0));
		map_print_compare(std_m, ft_m);
	}

	std::cout << "> insert(position): ";
	{
		std::map<std::string, int>::iterator std_it = std_m.begin();
		ft::map<std::string, int>::iterator ft_it = ft_m.begin();

		std_m.insert(std_it, std::make_pair("position", 0));
		ft_m.insert(ft_it, ft::make_pair("position", 0));
		map_print_compare(std_m, ft_m, false);
		std::cout << " ";

		std_it++;
		ft_it++;
		std_m.insert(std_it, std::make_pair("map", 42));
		ft_m.insert(ft_it, ft::make_pair("map", 42));
		map_print_compare(std_m, ft_m);
	}

	std::cout << "> insert(range): ";
	{
		std::vector<std::pair<std::string, int> > std_vt;
		std::vector<ft::pair<std::string, int> > ft_vt;
		for(int i = 1; i < 4; i++)
		{
			std::string str = std::to_string(i * 7);
			std_vt.push_back(std::make_pair(str, i));
			ft_vt.push_back(ft::make_pair(str, i));
		}

		std_m.insert(std_vt.begin(), std_vt.end());
		ft_m.insert(ft_vt.begin(), ft_vt.end());
		map_print_compare(std_m, ft_m);
	}
}

void m_erase()
{
	std::cout << "------------------ Erase -----------------\n";

	std::cout << "> erase(position): ";
}

void m_clear()
{
	std::cout << "------------------ Clear -----------------\n";

	std::cout << "> clear: ";
}

void m_swap()
{
	std::cout << "------------------ Swap ------------------\n";

	std::cout << "> swap: ";
}