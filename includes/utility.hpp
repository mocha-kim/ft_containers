/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:34:39 by sunhkim           #+#    #+#             */
/*   Updated: 2022/07/06 17:17:33 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_UTILITY_HPP
#define _FT_UTILITY_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
	public:
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair()
		: first(), second()
		{}

		template<class U, class V>
		pair (const pair<U, V>& copy)
		: first(copy.first), second(copy.second)
		{}

		pair (const first_type& fir, const second_type& sec)
		: first(fir), second(sec)
		{}

		pair& operator= (const pair& pr)
		{
			if (*this == pr)
				return (*this);
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}
	};

	template <class T1, class T2>
    ft::pair<T1,T2> make_pair(T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    }
}

#endif