/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:51:07 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/14 19:57:24 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_VECTOR_ITERATOR_HPP
#define _FT_VECTOR_ITERATOR_HPP

#include <cstddef>
#include "iterator.hpp"

namespace ft
{
	template<typename T>
	class vector_iterator : public random_access_iterator<T>
	{
	public:
		typedef T					value_type;
		typedef std::ptrdiff_t		difference_type;
		typedef value_type			*pointer;
		typedef value_type			&reference;
		
    	typedef pointer				iterator_type;

	protected:
		typedef random_access_iterator<T>	rand_iter;

		/*
		** Constructors, Distructor
		*/
		vector_iterator(const rand_iter &other) : rand_iter(other) {}

	public:
		vector_iterator() : rand_iter() {}
		vector_iterator(pointer p) : rand_iter(p) {}
		virtual ~vector_iterator() {}

		/*
		** Assignment operators
		*/
		vector_iterator &operator=(const vector_iterator &rhs)
		{
			this->_pointer = rhs._pointer;
			return *this;
		}
		vector_iterator &operator+=(int i)
		{
			this->_pointer += i;
			return *this;
		}
		vector_iterator &operator-=(int i)
		{
			this->_pointer -= i;
			return *this;
		}

		/*
		** Member and pointer operators
		*/
		reference operator*() { return *this->_pointer; }
		pointer operator->() { return this->_pointer; }
		reference operator[](difference_type i) { return this->_pointer[i]; }

		/*
		** Arithmetic operators
		*/
		vector_iterator operator++(int)
		{
			return rand_iter::operator++(0);
		}
		vector_iterator &operator++()
		{
			rand_iter::operator++();
			return *this;
		}
		vector_iterator operator--(int)
		{
			return rand_iter::operator--(0);
		}
		vector_iterator &operator--()
		{
			rand_iter::operator--();
			return *this;
		}
		vector_iterator operator+(difference_type i) const
		{
			return rand_iter::operator+(i);
		}
		friend vector_iterator operator+(difference_type i, const vector_iterator &rhs)
		{
			return rhs.operator+(i);
		};
		vector_iterator operator-(difference_type i) const
		{
			return rand_iter::operator-(i);
		}
		difference_type operator-(const rand_iter &rhs) const
		{
			return rand_iter::operator-(rhs);
		}
	}; // class vector_iterator

	template<typename T>
	class vector_const_iterator : public random_access_iterator<T>
	{
	public:
		typedef T					value_type;
		typedef const value_type	*pointer;
		typedef const value_type	&reference;
		typedef std::ptrdiff_t		difference_type;

	protected:
		typedef random_access_iterator<T>	rand_iter;

	public:
		/*
		** Constructors, Distructor
		*/
		vector_const_iterator() : rand_iter() {}
		vector_const_iterator(value_type *p) : rand_iter(p) {}
		vector_const_iterator(const rand_iter &other) : rand_iter(other) {}
		virtual ~vector_const_iterator() {}

		/*
		** Assignment operators
		*/
		vector_const_iterator &operator+=(difference_type i)
		{
			this->_pointer += i;
			return *this;
		}
		vector_const_iterator &operator-=(difference_type i)
		{
			this->_pointer -= i;
			return *this;
		}

		/*
		** Member and pointer operators
		*/
		reference operator*() const { return *this->_pointer; }
		pointer operator->() const { return this->_pointer; }
		reference operator[](difference_type i) const { return this->p[i]; }

		/*
		** Arithmetic operators
		*/
		vector_const_iterator operator++(int)
		{	
			return rand_iter::operator++(0);
		}
		vector_const_iterator &operator++(void)
		{
			rand_iter::operator++();
			return *this;
		}
		vector_const_iterator operator--(int)
		{
			return rand_iter::operator--(0);
		}
		vector_const_iterator &operator--()
		{
			--this->_pointer;
			return *this;
		}
		vector_const_iterator operator+(difference_type i) const
		{
			return rand_iter::operator+(i);
		}
		friend vector_const_iterator operator+(difference_type i, const vector_const_iterator &rhs)
		{
			return rhs.operator+(i);
		};
		vector_const_iterator operator-(difference_type i) const
		{
			return rand_iter::operator-(i);
		}
		difference_type operator-(const rand_iter &rhs) const
		{
			return rand_iter::operator-(rhs);
		}
	}; // class vector_const_iterator
}

#endif