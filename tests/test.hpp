/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:08:50 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/19 19:52:36 by sunhkim          ###   ########.fr       */
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

template<class T>
bool value_compare(const T& std, const T& ft) { return ft == std; }

template<class T>
bool print_compare(const T& std, const T& ft, bool newline = true)
{
	bool ret = value_compare(std, ft);
	std::string nl = newline ? "\n" : "";
	if (ret)
		std::cout << GRN "OK" NC << nl;
	else
		std::cout << RED "KO" NC << nl;
	return ret;
}

template<class T1, class T2>
bool pair_value_compare(const T1& std, const T2& ft)
{ 
	return (std.first == ft.first) && (std.second == ft.second); 
}

template<class T1, class T2>
bool pair_print_compare(const T1& std, const T2& ft, bool newline = true)
{
	bool ret = pair_value_compare(std, ft);
	std::string nl = newline ? "\n" : "";
	if (ret)
		std::cout << GRN "OK" NC << nl;
	else
		std::cout << RED "KO" NC << nl;
	return ret;
}

template<class T>
void print_value(const T& std, const T& ft)
{
    std::cout << ">  FT: " << ft << "\n";
    std::cout << "> STD: " << std << "\n";
}

template<class T1, class T2>
bool ite_compare(const T1& std, const T2& ft)
{
	if (ft.size() != std.size())
		return false;
	typename T1::const_iterator ite_std = std.begin();
	typename T2::const_iterator ite_ft = ft.begin(), ited_ft = ft.end();
	for (; ite_ft != ited_ft; ite_ft++)
	{
		if (*ite_ft != *ite_std)
			return false;
		ite_std++;
	}
	return true;
}

template<class T1, class T2>
bool ite_print_compare(const T1& std, const T2& ft, bool newline = true)
{
	bool ret = ite_compare(std, ft);
	std::string nl = newline ? "\n" : "";
	if (ret)
		std::cout << GRN "OK" NC << nl;
	else
		std::cout << RED "KO" NC << nl;
	return ret;
}

template<class T1, class T2>
bool map_compare(const T1& std, const T2& ft)
{
	if (ft.size() != std.size())
		return false;
	typename T1::const_iterator ite_std = std.begin();
	typename T2::const_iterator ite_ft = ft.begin(), ited_ft = ft.end();
	for (; ite_ft != ited_ft; ite_ft++)
	{
		if ((*ite_ft).first != (*ite_std).first
			|| (*ite_ft).second != (*ite_std).second)
			return false;
		ite_std++;
	}
	return true;
}

template<class T1, class T2>
bool map_print_compare(const T1& std, const T2& ft, bool newline = true)
{
	bool ret = map_compare(std, ft);
	std::string nl = newline ? "\n" : "";
	if (ret)
		std::cout << GRN "OK" NC << nl;
	else
		std::cout << RED "KO" NC << nl;
	return ret;
}

template<class T1, class T2>
bool st_compare(const T1& std, const T2& ft)
{
	if (ft.size() != std.size())
		return false;
	T1 tmp_std = std;
	T2 tmp_ft = ft;
	while(!tmp_ft.empty())
	{
		if (tmp_ft.top() != tmp_std.top())
			return false;
		tmp_ft.pop();
		tmp_std.pop();
	}
	return true;
}

template<class T1, class T2>
bool st_print_compare(const T1& std, const T2& ft, bool newline = true)
{
	bool ret = st_compare(std, ft);
	std::string nl = newline ? "\n" : "";
	if (ret)
		std::cout << GRN "OK" NC << nl;
	else
		std::cout << RED "KO" NC << nl;
	return ret;
}

int ft_test_ft();
int ft_test_std();

int vector_test();
int stack_test();
int map_test();

#endif