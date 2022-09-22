/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_t_4.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:00:35 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/22 15:29:12 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_test.hpp"
#include <vector>

void m_obeservers()
{
	std::cout << "---------------- Observers ---------------\n";

	std::map<int, float> std_m;
	ft::map<int, float> ft_m;
	{
		std::vector<std::pair<int, float> > std_vt;
		std::vector<ft::pair<int, float> > ft_vt;
		for(int i = 1; i < 5; i++)
		{
			std_vt.push_back(std::make_pair(i * 7, i * 0.11f));
			ft_vt.push_back(ft::make_pair(i * 7, i * 0.11f));
		}

		std_m.insert(std_vt.begin(), std_vt.end());
		ft_m.insert(ft_vt.begin(), ft_vt.end());
	}

	std::vector<bool> ft_key_result(ft_m.size());
	std::vector<bool> ft_value_result(ft_m.size());
	{
		int i = 0;
		ft::map<int, float>::iterator ite_ft = ft_m.end();
		for (ft::map<int, float>::iterator it_ft = ft_m.begin(); it_ft != ite_ft; it_ft++)
		{
			for (ft::map<int, float>::iterator it2_ft = ft_m.begin(); it2_ft != ite_ft; it2_ft++)
			{
				ft_key_result[i] = ft_m.key_comp()(it_ft->first, it2_ft->first);
				ft_value_result[i] = ft_m.value_comp()(*it_ft, *it2_ft);
				i++;
			}
		}
	}

	std::vector<bool> std_key_result(std_m.size());
	std::vector<bool> std_value_result(std_m.size());
	{
		int i = 0;
		std::map<int, float>::iterator ite_std = std_m.end();
		for (std::map<int, float>::iterator it_std = std_m.begin(); it_std != ite_std; it_std++)
		{
			for (std::map<int, float>::iterator it2_std =std_m.begin(); it2_std != ite_std; it2_std++)
			{
				std_key_result[i] = std_m.key_comp()(it_std->first, it2_std->first);
				std_value_result[i] = std_m.value_comp()(*it_std, *it2_std);
				i++;
			}
		}
	}

	bool flag = true;
	std::cout << "> key_compare: ";
	{
		for (size_t i = 0; i < std_m.size(); i++)
		{
			if (ft_key_result[i] != std_key_result[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			std::cout << GRN "OK\n" NC;
		else
			std::cout << RED "KO\n" NC;
	}

	std::cout << "> value_compare: ";
	{
		for (size_t i = 0; i < std_m.size(); i++)
		{
			if (ft_value_result[i] != std_value_result[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			std::cout << GRN "OK\n" NC;
		else
			std::cout << RED "KO\n" NC;
	}
}

void m_access()
{

}

void m_find()
{
	
}