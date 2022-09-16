/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:08:50 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/16 16:39:38 by sunhkim          ###   ########.fr       */
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

int ft_test_ft();
int ft_test_std();

template<class T>
bool print_value_compare(const T& ft, const T& std)
{
	bool ret = t1 == t2;
	if (ret)
		std::cout << GRN "OK\n" NC;
	else
		std::cout << RED "KO\n" NC;
	return ret;
}

template<class T>
bool print_value(const T& ft, const T& std)
{
    std::cout << ">  FT: " << ft << "\n";
    std::cout << "> STD: " << std << "\n";
    return t1 == t2 ? true : false;
}

#endif