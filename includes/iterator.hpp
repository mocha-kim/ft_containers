/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:14:12 by sunhkim           #+#    #+#             */
/*   Updated: 2022/07/19 16:57:44 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_ITERATOR_HPP
#define _FT_ITERATOR_HPP

namespace ft
{
	struct iterator_trait {};

	template<typename iterator>
	class ft_reverse_iterator : public iterator
	{
	public:
		using typename iterator::value_type;
		using typename iterator::pointer;
		using typename iterator::const_pointer;
		using typename iterator::reference;
		using typename iterator::const_reference;
		using typename iterator::difference_type;

	public:
		ft_reverse_iterator() : iterator() {}
		ft_reverse_iterator(iterator const &it) : iterator(it) {}
		ft_reverse_iterator(ft_reverse_iterator const &other): iterator(other.p) {}
		
		/*
		** Assignment operators
		*/
		ft_reverse_iterator &operator=(ft_reverse_iterator const &other)
		{
			this->p = other.p;
			return *this;
		}
		
		/*
		** Member and pointer operators
		*/
		value_type &operator*()
		{
			return *this->_pointer;
		};
		value_type *operator->()
		{
			return this->_pointer;
		};

		/*
		** Arithmetic operators
		*/
		ft_reverse_iterator operator++(int)
		{
			ft_reverse_iterator tmp(*this);
			tmp._pointer--;
			return tmp;
		}
		iterator &operator++()
		{
			return this->iterator::operator--();
		}
		ft_reverse_iterator operator--(int)
		{
			ft_reverse_iterator tmp(*this);
			tmp._pointer++;
			return tmp;
		}
		iterator &operator--()
		{
			return this->iterator::operator++();
		}
	};
}

#endif