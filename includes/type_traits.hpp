/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:31:13 by sunhkim           #+#    #+#             */
/*   Updated: 2022/07/27 22:17:32 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_TYPE_TRAITS_HPP
#define _FT_TYPE_TRAITS_HPP

namespace ft
{
	template <class T>
	struct is_integral : public std::false_type {};
	
	template <>
	struct is_integral<bool> : public std::true_type {};

	template <>
	struct is_integral<char> : public std::true_type {};

	template <>
	struct is_integral<char16_t> : public std::true_type {};

	template <>
	struct is_integral<char32_t> : public std::true_type {};

	template <>
	struct is_integral<wchar_t> : public std::true_type {};

	template <>
	struct is_integral<signed char> : public std::true_type {};

	template <>
	struct is_integral<short int> : public std::true_type {};

	template <>
	struct is_integral<int> : public std::true_type {};

	template <>
	struct is_integral<long int> : public std::true_type {};

	template <>
	struct is_integral<long long int> : public std::true_type {};

	template <>
	struct is_integral<unsigned char> : public std::true_type {};

	template <>
	struct is_integral<unsigned short int> : public std::true_type {};

	template <>
	struct is_integral<unsigned int> : public std::true_type {};

	template <>
	struct is_integral<unsigned long int> : public std::true_type {};
	
	template <>
	struct is_integral<unsigned long long int> : public std::true_type {};

	template <bool, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}

#endif