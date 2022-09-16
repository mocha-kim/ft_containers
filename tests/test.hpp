/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:08:50 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/16 17:16:53 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_TEST
#define FT_CONTAINERS_TEST

#include <iostream>
#include <string>
#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YLW "\e[0;33m"
#define BLU "\e[0;34m"
#define CYN "\e[0;36m"

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<class T1, class T2>
bool ite_compare(const T1& ft, const T2& std)
{
	if (ft.size() != std.size())
		return false;
	int size = ft.size();
	for (int i = 0; i < size; i++)
		if (ft[i] != std[i])
			return false;
	return true;
}

template<class T1, class T2>
bool ite_print_compare(const T1& ft, const T2& std)
{
	bool ret = ite_compare(ft, std);
	if (ret)
		std::cout << GRN "OK\n" NC;
	else
		std::cout << RED "KO\n" NC;
	return ret;
}

template<class T1, class T2>
bool st_compare(const T1& ft, const T2& std)
{
	if (ft.size() != std.size())
		return false;
	int size = ft.size();
	while(!ft.empty())
	{
		if (ft.top() != std.top())
			return false;
		ft.pop();
		std.pop();
	}
	return true;
}

template<class T1, class T2>
bool st_print_compare(const T1& ft, const T2& std)
{
	bool ret = st_compare(ft, std);
	if (ret)
		std::cout << GRN "OK\n" NC;
	else
		std::cout << RED "KO\n" NC;
	return ret;
}

template<class T1, class T2>
void print_value(const T1& ft, const T2& std)
{
    std::cout << ">  FT: " << ft << "\n";
    std::cout << "> STD: " << std << "\n";
}

int ft_test_ft();
int ft_test_std();

int vector_test();


#endif