/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:14:12 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/19 19:48:03 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_ITERATOR_HPP
#define _FT_ITERATOR_HPP

namespace ft
{
	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	}; // class iterator_traits

	template <class T>
	class iterator_traits<T*>
	{
		public:
			typedef 	ptrdiff_t							difference_type;
			typedef		T									value_type;
			typedef		T*									pointer;
			typedef		T&									reference;
			typedef		std::random_access_iterator_tag		iterator_category;
	}; // class iterator_traits<T*>

	template <class T>
	class iterator_traits<const T*>
	{
		public:
			typedef 	ptrdiff_t							difference_type;
			typedef		T									value_type;
			typedef		const T*							pointer;
			typedef		const T&							reference;
			typedef		std::random_access_iterator_tag		iterator_category;
	}; // class iterator_traits<const T*>

	template <typename T>
	class random_access_iterator : public iterator_traits<T*>
	{
	public:
		typedef T			value_type;
		typedef ptrdiff_t	difference_type;
		typedef T*			pointer;
		typedef T&			reference;

	protected:
		pointer	_pointer;

	public:
		/*
		** Constructors, Distructor
		*/
		random_access_iterator() : _pointer(NULL) {}
		random_access_iterator(pointer it) : _pointer(it) {}
		random_access_iterator(const random_access_iterator &other) : _pointer(other._pointer) {}
		virtual ~random_access_iterator() {}

		/*
		** Assignment operators
		*/
		random_access_iterator &operator=(const random_access_iterator &rhs)
		{
			if (this == &rhs)
				return (*this);
			_pointer = rhs._pointer;
			return *this;
		}

		/*
		** Arithmetic operators
		*/
		random_access_iterator operator++(int)
		{
			random_access_iterator tmp = *this;
			++this->_pointer;
			return tmp;
		}
		random_access_iterator &operator++()
		{
			++this->_pointer;
			return *this;
		}
		random_access_iterator operator--(int)
		{
			random_access_iterator tmp = *this;
			--this->_pointer;
			return tmp;
		}
		random_access_iterator &operator--()
		{
			--this->_pointer;
			return *this;
		}
		random_access_iterator operator+(difference_type i) const
		{
			random_access_iterator tmp = *this;
			tmp._pointer += i;
			return tmp;
		}
		friend random_access_iterator operator+(difference_type i, const random_access_iterator &rhs)
		{
			return rhs.operator+(i);
		};
		random_access_iterator operator-(difference_type i) const
		{
			random_access_iterator tmp = *this;
			tmp._pointer -= i;
			return tmp;
		}
		difference_type operator-(const random_access_iterator &rhs) const
		{
			random_access_iterator tmp = *this;
			return tmp._pointer - rhs._pointer;
		}

		/*
		** Comparison operators
		*/
		bool operator==(const random_access_iterator &rhs) const { return _pointer == rhs._pointer;}
		bool operator!=(const random_access_iterator &rhs) const { return _pointer != rhs._pointer;}
		bool operator<(const random_access_iterator &rhs) const { return _pointer < rhs._pointer;}
		bool operator>(const random_access_iterator &rhs) const { return _pointer > rhs._pointer;}
		bool operator<=(const random_access_iterator &rhs) const { return !(_pointer > rhs._pointer);}
		bool operator>=(const random_access_iterator &rhs) const { return !( _pointer < rhs._pointer);}
	}; // class random_access_iterator

	template <class Iter>
	class reverse_iterator
	{
	public:
		typedef Iter							iterator_type;
		typedef typename Iter::value_type		value_type;
		typedef typename Iter::difference_type	difference_type;
		typedef typename Iter::pointer			pointer;
		typedef typename Iter::reference		reference;
		
		typedef typename Iter::iterator_category	iterator_category;

	protected:
		iterator_type	_pointer;

	public:
		/*
		** Constructors, Distructor
		*/
		reverse_iterator() : _pointer(NULL) { }
		explicit reverse_iterator(iterator_type it) : _pointer(it) {}
		template <class It>
		reverse_iterator (const reverse_iterator<It> &rev_iter) : _pointer(rev_iter.base()) {}
		virtual ~reverse_iterator() {}

		iterator_type base() const { return _pointer; }

		/*
		** Assignment operators
		*/
		reverse_iterator &operator=(const reverse_iterator &rhs)
		{
			if (this != &rhs)
				_pointer = rhs.base();
			return (*this);
		}
		reverse_iterator &operator+=(difference_type i)
		{
			_pointer -= i;
			return (*this);
		}
		reverse_iterator &operator-=(difference_type i)
		{
			_pointer += i;
			return (*this);
		}
		
		/*
		** Member and pointer operators
		*/
		reference operator*() const
		{
			Iter tmp(_pointer);
			--tmp;
			return tmp.operator*();
		}
		pointer operator->() const
		{
			return &(operator*());
		}
		reference operator[](difference_type i)
		{
			return *operator+(i);
		}

		/*
		** Arithmetic operators
		*/
		reverse_iterator &operator++()
		{
			--_pointer;
			return *this;
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			operator++();
			return tmp;
		}
		reverse_iterator &operator--()
		{
			++_pointer;
			return *this;
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			operator--();
			return tmp;
		}
		reverse_iterator operator+(const int i) const
		{
			reverse_iterator tmp = *this;
			tmp._pointer -= i;
			return tmp;
		}
		friend reverse_iterator operator+(difference_type i, const reverse_iterator &rhs)
		{
			return rhs.operator+(i);
		};
		reverse_iterator operator-(difference_type i)
		{
			reverse_iterator tmp = *this;
			tmp._pointer += i;
			return tmp;
		}
		template < class It >
		difference_type operator-(const reverse_iterator<It> &rhs) const
		{
			return rhs.base().operator-(_pointer);
		}

		/*
		** Comparison operators
		*/
		template <class It>
		bool operator==(const reverse_iterator<It> &rhs) const { return _pointer.operator==(rhs.base()); }
		template <class It>
		bool operator!=(const reverse_iterator<It> &rhs) const { return _pointer.operator!=(rhs.base()); }
		template <class It>
		bool operator<(const reverse_iterator<It> &rhs) const { return _pointer.operator>(rhs.base()); }
		template <class It>
		bool operator>(const reverse_iterator<It> &rhs) const { return _pointer.operator<(rhs.base()); }
		template <class It>
		bool operator<=(const reverse_iterator<It> &rhs) const { return _pointer.operator>=(rhs.base()); }
		template <class It>
		bool operator>=(const reverse_iterator<It> &rhs) const { return _pointer.operator<=(rhs.base()); }
	}; // class reverse_iterator

	template <class It>
	size_t	distance(It first, It last)
	{
		size_t	dist = 0;

		while (first != last)
		{
			first++;
			dist++;
		}
		return (dist);
	}
}

#endif