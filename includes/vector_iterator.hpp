/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:51:07 by sunhkim           #+#    #+#             */
/*   Updated: 2022/07/06 17:17:11 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_VECTOR_ITERATOR_HPP
#define _FT_VECTOR_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template<typename T>
	class vector_iterator: iterator_trait
	{
	public:
		typedef T value_type;
		typedef value_type* pointer;
		typedef value_type const * const_pointer;
		typedef value_type& reference;
		typedef value_type const & const_reference;
		typedef std::ptrdiff_t difference_type;

	protected:
		pointer p;

	public:
		vector_iterator(): p(nullptr) {};
		vector_iterator(pointer p): p(p) {};
		vector_iterator(vector_iterator const &other): p(other.p) {}
		virtual ~vector_iterator() {}

		vector_iterator &operator=(vector_iterator const &other)
		{
			this->p = other.p;
			return (*this);
		}

		reference operator*()
		{
			return (*this->p);
		}
		const_reference operator*() const
		{
			return (*this->p);
		}
		pointer operator->() {
			return (this->p);
		}
		const_pointer operator->() const {
			return (this->p);
		}
		reference operator[](int val)
		{
			return (*(this->p + val));
		}
		const_reference operator[](int val) const
		{
			return (*(this->p + val));
		}

		vector_iterator operator++(int)
		{
			vector_iterator tmp(*this);
			++this->p;
			return (tmp);
		}
		vector_iterator &operator++()
		{
			++this->p;
			return (*this);
		}
		vector_iterator operator--(int)
		{
			vector_iterator tmp(*this);
			--this->p;
			return (tmp);
		}
		vector_iterator &operator--()
		{
			--this->p;
			return (*this);
		}

		vector_iterator &operator+=(int value)
		{
			this->p += value;
			return (*this);
		}
		vector_iterator operator+(int value) const {
			vector_iterator tmp(*this);
			return (tmp += value);
		}
		vector_iterator &operator-=(int value) {
			this->p -= value;
			return (*this);
		}
		vector_iterator operator-(int value) const {
			vector_iterator tmp(*this);
			return (tmp -= value);
		}
		difference_type operator-(vector_iterator const &other) const {
			return (this->p - other.p);
		}

		bool operator==(vector_iterator const &other) const {
			return (this->p == other.p);
		}
		bool operator!=(vector_iterator const &other) const {
			return (this->p != other.p);
		}
		bool operator<(vector_iterator const &other) const {
			return (this->p < other.p);
		}
		bool operator<=(vector_iterator const &other) const {
			return (this->p <= other.p);
		}
		bool operator>(vector_iterator const &other) const {
			return (this->p > other.p);
		}
		bool operator>=(vector_iterator const &other) const {
			return (this->p >= other.p);
		}
	}; //class vector_iterator
}

#endif