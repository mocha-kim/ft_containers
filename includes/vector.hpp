/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:56:13 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/12 21:25:05 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <limits>
#include <memory>
#include "type_traits.hpp"
#include "vector_iterator.hpp"
#include "algorithm.hpp"

namespace ft
{
	/*  vector	*/
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T					value_type;
		typedef Alloc				allocator_type;
		typedef std::size_t			size_type;
		typedef std::ptrdiff_t		difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		
		typedef ft::vector_iterator<T>					iterator;
		typedef ft::vector_const_iterator<T>			const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	protected:
		typedef vector<T> _this;

		pointer			_container;
		allocator_type	_allocator;
		size_type		_length;
		size_type		_capacity;

	public:
		/*
		** Constructors, Distructor
		*/
		explicit vector(const allocator_type &allocator = allocator_type())
		: _container(0), _allocator(allocator), _length(0), _capacity(0)
		{
			_container = _allocator.allocate(0);
		};
		template <class InputIterator>
		vector(InputIterator begin, InputIterator end, const allocator_type &allocator = allocator_type())
		: _container(0), _allocator(allocator), _length(0), _capacity(0)
		{
			_container = _allocator.allocate(0);
			assign(begin, end);
		};
		vector(size_type n, const_reference value = value_type(), const allocator_type &allocator = allocator_type())
		: _container(0), _allocator(allocator), _length(0), _capacity(0)
		{
			_container = _allocator.allocate(0);
			assign(n, value);
		};
		vector(const vector &other)
		: _container(0), _allocator(other._allocator), _length(0), _capacity(0)
		{
			*this = other;
		};
		~vector()
		{
			_allocator.deallocate(_container, _capacity);
			_container = NULL;
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
		iterator begin() { return iterator(&(_container[0])); };
		const_iterator begin() const { return const_iterator(&(_container[0])); };
		iterator end() { return iterator(&(_container[_length])); };
		const_iterator end() const { return const_iterator(&(_container[_length])); };
		reverse_iterator rbegin() { return reverse_iterator(end()); };
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); };
		reverse_iterator rend() { return (reverse_iterator(begin())); };
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };

		/*
		** Capacity
		*/
		size_type size() const { return _length; };
		size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(value_type); };
		void resize(size_type n, value_type value = value_type())
		{
			if (n < _length)
				for (iterator it = end(); _length > n; it--)
					pop_back();
			else
				for (iterator it = end(); _length < n; it++)
					push_back(value);
		};
		size_type capacity() const { return _capacity; };
		bool empty() const { return _length == 0; };
		void reserve(size_type n)
		{
			if (n > this->max_size())
				throw std::length_error("vector::reserve");
			if (n <= this->_capacity)	
				return;
			n = _calc_capacity(n);
			pointer tmp = _allocator.allocate(n);
			_capacity = n;
			for (size_type i = 0; i < n && i < _length; i++)
					tmp[i] = _container[i];
			if (_capacity != 0)
				_allocator.deallocate(_container, _capacity);
			_container = tmp;
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
				throw std::out_of_range("index out_of_range");
			return _container[n];
		};
		const_reference at(size_type n) const
		{
			if (n >= _length || n < 0)
				throw std::out_of_range("index out_of_range");
			return _container[n];
		};
		reference front() { return _container[0]; };
		const_reference front() const { return _container[0]; };
		reference back() { return _container[_length - 1]; };
		const_reference back() const { return _container[_length - 1]; };

		/*
		** Modifiers
		*/
		void assign(size_type n, const value_type &value)
		{
			if (n > _capacity)
			{
				_allocator.deallocate(_container, _capacity);
				_capacity = n;
				_container = _allocator.allocate(_capacity);
			}
			for (size_t i = 0; i < n; i++)
				_container[i] = value;
			_length = n;
		};
		template <class InputIterator>
        void assign(InputIterator first, InputIterator last
			, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			size_t n = ft::distance(first, last);
			if (n > _capacity)
			{
				_allocator.deallocate(_container, _capacity);
				_capacity = n;
				_container = _allocator.allocate(_capacity);
			}
			size_t i = 0;
			for (; first != last; first++)
			{
				_container[i] = *first;
				i++;
			}
			_length = n;
        }
		void push_back(const value_type &value)
		{
			if (_capacity == 0)
				this->reserve(1);
			else if (_capacity <= _length)
				this->reserve(_calc_capacity(_length + 1));
			_allocator.construct(_container + _length, value);
			_length++;
		};
		void pop_back()
		{
			if (_length)
			{
				_allocator.destroy(&(_container[_length - 1]));
				_length--;
			}
		};
		iterator insert(iterator position, const value_type &value)
		{
			size_type offset = position - this->begin();

			if (_capacity < _length + 1)
				reserve(_length + 1);

			pointer cur = _container + _length;
			pointer end = _container + offset;

			for(; cur != end; cur--) 
				_allocator.construct(cur, *(cur - 1));
				
			_allocator.construct(end, value);
			_length++;
			return (end);
		};
		void insert(iterator position, size_type n, const value_type &value)
		{
			if (n == 0)
				return;
			
			size_type offset = position - this->begin();

			if (_capacity < _length + n)
				reserve(_length + n);
				
			pointer cur = _container + _length + n - 1;
			pointer end = _container + offset + n - 1;
		
			for(; cur != end; cur--)
				_allocator.construct(cur, *(cur - n));

			_length += n;
			for (size_type i = 0; i < n; i++)
				_allocator.construct(_container + offset + n - i - 1, value);
		};
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last
			, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			if (first == last)
				return;
			
			difference_type offset = position - this->begin();
			size_type n = ft::distance(first, last);

			if (_capacity < _length + n)
				reserve(_length + n);
			
			pointer cur = _container + _length + n - 1;
			pointer end = _container + offset + n - 1;
			for (; cur != end; cur--)
				_allocator.construct(cur, *(cur - n));
				
			_length += n;
			for (; n > 0; n--)
			{
				last--;
				this->_allocator.construct(_container + offset - 1 + n, *last);
			}
		}
		iterator erase(iterator position)
		{
			iterator i = position;
			iterator end = this->end();
			for (; i + 1 != end; i++)
				i[0] = i[1];
			_allocator.destroy(_container + _length - 1);
			_length--;
			return position;
		};
		iterator erase(iterator first, iterator last)
		{
			iterator ret = first;
			iterator end = this->end();
			size_type del_length = ft::distance(first, last);
			for (; last != end; last++)
			{
				*first = *last;
				first++;
			}
			while (del_length > 0)
			{
				_length--;
				_allocator.destroy(&_container[_length]);
				del_length--;
			}
			return (ret);
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

	private:
		size_t	_calc_capacity(size_t n)
		{
			if (n <= _length * 2)
				return (_length * 2);
			return (n);
		}
	}; // class vector

	template<class T, class Alloc>
	bool operator==(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		if (a.size() != b.size())
			return false;
		unsigned long i = -1;
		while (++i < a.size())
		{
			if (a[i] != b[i])
				return false;
		}
		return (true);
	};
	template<class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	};

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		size_t i;
		size_t n;

		if (lhs.size() > rhs.size())
			n = rhs.size();
		else
			n = lhs.size();
		i = 0;
		while (i < n)
		{
			if (lhs.at(i) != rhs.at(i))
				return lhs.at(i) < rhs.at(i);
			i++;
		}
		return lhs.size() < rhs.size();
	}
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs) && !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs > rhs);
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}
	
	template <class T, class Alloc>
	void swap(vector<T, Alloc> &a, vector<T, Alloc> &b)
	{
		a.swap(b);
	}
} // namespace ft

#endif
