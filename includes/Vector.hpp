/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:56:13 by sunhkim           #+#    #+#             */
/*   Updated: 2022/07/13 14:59:14 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "iterator.hpp"
#include "vector_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T					value_type;
		typedef Alloc				allocator_type;
		typedef std::size_t			size_type;
		typedef std::ptrdiff_t		difference_type;
		typedef value_type			&reference;
		typedef value_type const	&const_reference;
		typedef value_type			*pointer;
		typedef value_type const	*const_pointer;
		
		typedef vector_iterator<T> iterator;
		typedef vector_iterator<const T> const_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		typedef reverse_iterator<const_iterator> const_reverse_iterator;

	protected:
		typedef Vector<T> _this;

		pointer		_pointer;
		size_type	_length;
		size_type	_capacity;

	public:
		
	};
}

#endif