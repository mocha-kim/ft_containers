/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:14:12 by sunhkim           #+#    #+#             */
/*   Updated: 2022/07/13 14:54:29 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_ITERATOR_HPP
#define _FT_ITERATOR_HPP

namespace ft
{
	struct iterator_trait {};

	template<typename iterator>
	class reverse_iterator : public iterator
	{
	public:
		using typename iterator::value_type;
		using typename iterator::pointer;
		using typename iterator::const_pointer;
		using typename iterator::reference;
		using typename iterator::const_reference;
		using typename iterator::difference_type;

	public:
		reverse_iterator() : iterator() {}
		reverse_iterator(iterator const &it) : iterator(it) {}
		reverse_iterator(reverse_iterator const &other): iterator(other.p) {}
		
		/*
		** Assignment operators
		*/
		reverse_iterator &operator=(reverse_iterator const &other)
		{
			this->p = other.p;
			return (*this);
		}
		
		/*
		** Member and pointer operators
		*/
		reference operator*()
		{
			iterator tmp(*this);
			return (*--tmp);
		}
		const_reference operator*() const
		{
			iterator tmp(*this);
			return (*--tmp);
		}
		pointer operator->()
		{
			iterator tmp(*this);
			return (&*--tmp);
		}
		const_pointer operator->() const
		{
			iterator tmp(*this);
			return (&*--tmp);
		}

		/*
		** Arithmetic operators
		*/
		reverse_iterator operator++(int)
		{
			reverse_iterator tmp(*this);
			operator++();
			return (tmp);
		}
		iterator &operator++()
		{
			return (this->iterator::operator--());
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp(*this);
			operator--();
			return (tmp);
		}
		iterator &operator--()
		{
			return (this->iterator::operator++());
		}
	};
}

#endif