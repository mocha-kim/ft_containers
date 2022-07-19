/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:51:07 by sunhkim           #+#    #+#             */
/*   Updated: 2022/07/19 16:55:35 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_VECTOR_ITERATOR_HPP
#define _FT_VECTOR_ITERATOR_HPP

#include <cstddef>

namespace ft
{
	template<typename T>
	class vector_iterator : iterator_trait
	{
	public:
		typedef T					value_type;
		typedef value_type			*pointer;
		typedef value_type const	*const_pointer;
		typedef value_type			&reference;
		typedef value_type const	&const_reference;
		typedef std::ptrdiff_t		difference_type;

	protected:
		pointer _pointer;

	public:
		vector_iterator() : _pointer(nullptr) {};
		vector_iterator(pointer p) : _pointer(p) {};
		vector_iterator(vector_iterator const &other) : _pointer(other._pointer) {}
		virtual ~vector_iterator() {}

		/*
		** Assignment operators
		*/
		vector_iterator &operator=(vector_iterator const &other)
		{
			this->_pointer = other._pointer;
			return *this;
		}
		vector_iterator &operator+=(int value)
		{
			this->_pointer += value;
			return *this;
		}
		vector_iterator &operator-=(int value)
		{
			this->_pointer -= value;
			return *this;
		}

		/*
		** Member and pointer operators
		*/
		reference operator*() { return (*this->_pointer); }
		const_reference operator*() const { return (*this->_pointer); }
		pointer operator->() { return (this->_pointer); }
		const_pointer operator->() const { return (this->_pointer); }
		reference operator[](int val) { return (*(this->_pointer + val)); }
		const_reference operator[](int val) const { return (*(this->_pointer + val)); }

		/*
		** Arithmetic operators
		*/
		vector_iterator operator++(int)
		{
			vector_iterator tmp(*this);
			++this->_pointer;
			return tmp;
		}
		vector_iterator &operator++()
		{
			++this->_pointer;
			return *this;
		}
		vector_iterator operator--(int)
		{
			vector_iterator tmp(*this);
			--this->_pointer;
			return tmp;
		}
		vector_iterator &operator--()
		{
			--this->_pointer;
			return *this;
		}

		vector_iterator operator+(int value) const
		{
			vector_iterator tmp(*this);
			return tmp += value;
		}
		vector_iterator operator-(int value) const
		{
			vector_iterator tmp(*this);
			return tmp -= value;
		}
		difference_type operator-(vector_iterator const &other) const
		{
			return this->_pointer - other._pointer;
		}

		/*
		** Comparison operators
		*/
		bool operator==(vector_iterator const &other) const { return (this->_pointer == other._pointer); }
		bool operator!=(vector_iterator const &other) const { return (this->_pointer != other._pointer); }
		bool operator<(vector_iterator const &other) const { return (this->_pointer < other._pointer); }
		bool operator<=(vector_iterator const &other) const { return (this->_pointer <= other._pointer); }
		bool operator>(vector_iterator const &other) const { return (this->_pointer > other._pointer); }
		bool operator>=(vector_iterator const &other) const { return (this->_pointer >= other._pointer); }
	}; //class vector_iterator

	template <typename T>
	bool operator==(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return lhs._e == rhs._e;
	}

	template <typename T>
	bool operator!=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T>
	bool operator<(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return lhs._e < rhs._e;
	}

	template <typename T>
	bool operator<=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return !(lhs > rhs);
	}
	
	template <typename T>
	bool operator>(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return rhs < lhs;
	}

	template <typename T>
	bool operator>=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return !(lhs < rhs);
	}

	template <typename T>
	vector_iterator<T> operator+(const vector_iterator<T> &ite, std::size_t offset)
	{
		vector_iterator<T> res = ite;
		return res += offset;
	}

	template <typename T>
	vector_iterator<T> operator+(std::size_t offset, const vector_iterator<T> &ite)
	{
		return ite + offset;
	}

	template <typename T>
	vector_iterator<T> operator-(const vector_iterator<T> &ite, std::size_t offset)
	{
		vector_iterator<T> res = ite;
		return res -= offset;
	}

	template <typename T>
	ptrdiff_t operator-(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs)
	{
		return lhs._e - rhs._e;
	}
}

#endif