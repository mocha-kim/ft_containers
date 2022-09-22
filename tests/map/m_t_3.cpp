/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_t_3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:22:56 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/22 14:59:23 by sunhkim          ###   ########.fr       */
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

	std::map<std::string, int> std_m;
	ft::map<std::string, int> ft_m;
	{
		std::vector<std::pair<std::string, int> > std_vt;
		std::vector<ft::pair<std::string, int> > ft_vt;
		for(int i = 1; i < 5; i++)
		{
			std::string str = std::to_string(i * 7);
			std_vt.push_back(std::make_pair(str, i));
			ft_vt.push_back(ft::make_pair(str, i));
		}

		std_m.insert(std_vt.begin(), std_vt.end());
		ft_m.insert(ft_vt.begin(), ft_vt.end());
	}

	std::cout << "> erase(key): ";
	{
		std_m.erase("21");
		ft_m.erase("21");
		map_print_compare(std_m, ft_m);
	}

	std::cout << "> erase(position): ";
	{
		std::map<std::string, int>::iterator std_it = std_m.begin();
		ft::map<std::string, int>::iterator ft_it = ft_m.begin();
		std_it++;
		ft_it++;

		std_m.erase(std_it);
		ft_m.erase(ft_it);
		map_print_compare(std_m, ft_m);
	}

	std::cout << "> erase(range): ";
	{
		{
			std::vector<std::pair<std::string, int> > std_vt;
			std::vector<ft::pair<std::string, int> > ft_vt;
			for(int i = 1; i < 5; i++)
			{
				std::string str = std::to_string(i * 11);
				std_vt.push_back(std::make_pair(str, i));
				ft_vt.push_back(ft::make_pair(str, i));
			}

			std_m.insert(std_vt.begin(), std_vt.end());
			ft_m.insert(ft_vt.begin(), ft_vt.end());
		}
		std::map<std::string, int>::iterator std_it = std_m.begin();
		ft::map<std::string, int>::iterator ft_it = ft_m.begin();
		std::map<std::string, int>::iterator std_ite = std_m.end();
		ft::map<std::string, int>::iterator ft_ite = ft_m.end();
		
		std_it++;
		ft_it++;
		std_it++;
		ft_it++;
		std_ite--;
		ft_ite--;
		std_ite--;
		ft_ite--;
		std_ite--;
		ft_ite--;

		std_m.erase(std_it, std_ite);
		ft_m.erase(ft_it, ft_ite);
		map_print_compare(std_m, ft_m);
	}
}

void m_clear()
{
	std::cout << "------------------ Clear -----------------\n";

	std::map<std::string, int> std_m;
	ft::map<std::string, int> ft_m;

	{
		std::vector<std::pair<std::string, int> > std_vt;
		std::vector<ft::pair<std::string, int> > ft_vt;
		for(int i = 1; i < 5; i++)
		{
			std::string str = std::to_string(i * 11);
			std_vt.push_back(std::make_pair(str, i));
			ft_vt.push_back(ft::make_pair(str, i));
		}

		std_m.insert(std_vt.begin(), std_vt.end());
		ft_m.insert(ft_vt.begin(), ft_vt.end());
	}

	std::cout << "> clear: ";
	std_m.clear();
	ft_m.clear();

	print_compare(std_m.size(), ft_m.size(), false);
	std::cout << " ";
	
	map_print_compare(std_m, ft_m);
}

void m_swap()
{
	std::cout << "------------------ Swap ------------------\n";

	std::cout << "> swap: ";

	std::map<std::string, int> std_m1, std_m2, std_m3;
	ft::map<std::string, int> ft_m1, ft_m2, ft_m3;
	{
		std::vector<std::pair<std::string, int> > std_vt;
		std::vector<ft::pair<std::string, int> > ft_vt;
		for(int i = 1; i < 5; i++)
		{
			std::string str = std::to_string(i * 11);
			std_vt.push_back(std::make_pair(str, i));
			ft_vt.push_back(ft::make_pair(str, i));
		}

		std_m1.insert(std_vt.begin(), std_vt.end());
		ft_m1.insert(ft_vt.begin(), ft_vt.end());
	}

	std_m2.insert(std::make_pair("test", 42));
	ft_m2.insert(ft::make_pair("test", 42));

	std_m1.swap(std_m2);
	ft_m1.swap(ft_m2);
	map_print_compare(std_m1, ft_m1, false);
	std::cout << " ";
	map_print_compare(std_m2, ft_m2, false);
	std::cout << " ";

	std_m1.swap(std_m3);
	ft_m1.swap(ft_m3);
	map_print_compare(std_m1, ft_m1, false);
	std::cout << " ";
	map_print_compare(std_m3, ft_m3);
}