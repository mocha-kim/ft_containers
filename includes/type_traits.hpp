/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:31:13 by sunhkim           #+#    #+#             */
/*   Updated: 2022/07/06 17:17:50 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_TYPE_TRAITS_HPP
#define _FT_TYPE_TRAITS_HPP

namespace ft
{
	template <class T> struct is_integral;

	template <bool, typename T = void>
	struct enable_if
	{ };

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}

#endif