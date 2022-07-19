/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:56:13 by sunhkim           #+#    #+#             */
/*   Updated: 2022/07/19 16:43:26 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "iterator.hpp"
#include "vector_iterator.hpp"
#include "algorithm.hpp"

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
		typedef ft_reverse_iterator<iterator> reverse_iterator;
		typedef ft_reverse_iterator<const_iterator> const_reverse_iterator;

	protected:
		typedef vector<T> _this;

		pointer _container;
		allocator_type _allocator;
		size_type	_length;
		size_type	_capacity;

	public:
		/*
		** Constructors, Distructor
		*/
		explicit vector(const allocator_type &allocator = allocator_type())
		: _length(0), _capacity(0), _container(0), _allocator(allocator)
		{
			_container = _allocator.allocate(0);
		};
		template <class InputIterator>
		vector(InputIterator begin, InputIterator end, const allocator_type &allocator = allocator_type())
		: _length(0), _capacity(0), _container(0), _allocator(allocator)
		{
			_container = _allocator.allocate(0);
			assign(begin, end);
		};
		vector(size_type n, const_reference value = value_type(), const allocator_type &allocator = allocator_type())
		: _length(0), _capacity(0), _container(0), _allocator(allocator)
		{
			_container = _allocator.allocate(0);
			assign(n, value);
		};
		vector(const vector &other)
		: _length(0), _capacity(0), _container(0), _allocator(other._allocator)
		{
			*this = other;
		};
		~vector()
		{
			_allocator.deallocate(_container, _capacity);
		};

		/*
		** Operators
		*/
		vector &operator=(const vector &other)
		{
			if (_container != 0)
				_allocator.deallocate(_container, _capacity);
			_allocator = other._allocator;
			_capacity = 0;
			_length = 0;
			_container = _allocator.allocate(0);
			assign(other.begin(), other.end());
			return *this;
		};

		/*
		** Iterators
		*/
		iterator begin() { return iterator(_container); };
		const_iterator begin() const { return const_iterator(_container); };
		iterator end() { return iterator(_container + _length); };
		const_iterator end() const { return const_iterator(_container + _length); };
		reverse_iterator rbegin() { return reverse_iterator(_container + _length - 1); };
		const_reverse_iterator rbegin() const { return const_reverse_iterator(_container + _length - 1); };
		reverse_iterator rend() { return (reverse_iterator(_container - 1)); };
		const_reverse_iterator rend() const { return const_reverse_iterator(_container - 1); };

		/*
		** Capacity
		*/
		size_type size() const { return _length; };
		size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(value_type); };
		void resize(size_type n, value_type value = value_type())
		{
			while (n < _length)
				pop_back();
			while (n > _length)
				push_back(value);
		};
		size_type capacity() const { return _capacity; };
		bool empty() const { return _length == 0; };
		void reserve(size_type n)
		{
			if (n > _capacity)
			{
				size_type i = -1;
				pointer	tmp;
				tmp  = _allocator.allocate(n);
				_capacity = n;
				while (++i < _length)
					tmp[i] = _container[i];
				_allocator.deallocate(_container, _capacity);
				_container = tmp;
			}
		};

		/*
		** Element access
		*/
		reference operator[](size_type n)
		{
			return (_container[n]);
		};
		const_reference operator[](size_type n) const
		{
			return (_container[n]);
		};
		reference at(size_type n)
		{
			if (n >= _length || n < 0)
				throw std::length_error("index out-of-bounds");
			return _container[n];
		};
		const_reference at(size_type n) const
		{
			if (n >= _length || n < 0)
				throw std::length_error("index out-of-bounds");
			return _container[n];
		};
		reference front() { return _container[0]; };
		const_reference front() const { return _container[0]; };
		reference back() { return _container[_length - 1]; };
		const_reference back() const { return _container[_length - 1]; };

		/*
		** Modifiers
		*/
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			clear();
			insert(begin(), first, last);
		};
		void assign(size_type n, const value_type &value)
		{
			clear();
			insert(begin(), n, value);
		};
		void push_back(const value_type &value)
		{
			if (_length + 1 > _capacity)
				reserve(_length + 1);
			_container[_length++] = value;
		};
		void pop_back()
		{
			if (_length)
				_length--;
		};
		iterator insert(iterator position, const value_type &value)
		{
			size_type i = 0;
			iterator it = begin();
			while (it + i != position && i < _length)
				i++;
			if (_capacity < _length + 1)
				reserve(_length + 1);
			size_type j = _capacity - 1;
			while (j > i)
			{
				_container[j] = _container[j - 1];
				j--;
			}
			_container[i] = value;
			_length++;
			return (iterator(&_container[i]));
		};
		void insert(iterator position, size_type n, const value_type &value)
		{
			while (n--)
				position = insert(position, value);
		};
		template <class InputIterator>
		void insert(iterator position, InputIterator begin, InputIterator end)
		{
			while (begin != end)
			{
				position = insert(position, *begin) + 1;
				++begin;
			}
		};
		iterator erase(iterator position)
		{
			iterator cursor = position;
			while (cursor + 1 != end())
			{
				*cursor = *(cursor + 1);
				cursor++;
			}
			_length--;
			return (iterator(position));
		};
		iterator erase(iterator begin, iterator end)
		{
			while (begin != end)
			{
				erase(begin);
				end--;
			}
			return (iterator(begin));
		};
		void clear()
		{
			erase(begin(), end());
		};
		void swap(vector &other)
		{
			ft::swap(_container, other._container);
			ft::swap(_capacity, other._capacity);
			ft::swap(_length, other._length);
		};
	}; // class vector

	template<class T, class Alloc>
	bool operator==(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		if (a.size() != b.size())
			return (false);
		unsigned long i = -1;
		while (++i < a.size())
		{
			if (a[i] != b[i])
				return (false);
		}
		return (true);
	};
	template<class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		return (!(a == b));
	};
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc> &a, const vector<T,Alloc> &b)
	{
		size_t		i;
		size_t		n;

		if (a.size() > b.size())
			n = b.size();
		else
			n = a.size();
		i = 0;
		while (i < n)
		{
			if (a.at(i) != b.at(i))
				return (a.at(i) < b.at(i));
			i++;
		}
		return (a.size() < b.size());
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc> &a, const vector<T,Alloc> &b)
	{
		return (a < b || a == b);
	}
	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc> &a, const vector<T,Alloc> &b)
	{
		return (!(a < b) && !(a == b));
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc> &a, const vector<T,Alloc> &b)
	{
		return (!(a < b));
	}
	template <class T, class Alloc>
	void swap(vector<T, Alloc> &a, vector<T, Alloc> &b)
	{
		a.swap(b);
	};
} // namespace ft

#endif