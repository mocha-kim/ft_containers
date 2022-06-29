/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:11:48 by sunhkim           #+#    #+#             */
/*   Updated: 2022/06/29 17:58:30 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

namespace ft
{
	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template <class T>
	struct less : binary_function<T, T, bool>
	{
		bool operator() (const T& x, const T& y) const { return (x < y); }
	};
}

#endif