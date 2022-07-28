/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:14:12 by sunhkim           #+#    #+#             */
/*   Updated: 2022/07/28 16:43:15 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_ITERATOR_HPP
#define _FT_ITERATOR_HPP

namespace ft
{
	struct iterator_trait {};

	template<typename Iterator>
	class ft_reverse_iterator : public Iterator
	{
	public:
		using typename Iterator::value_type;
		using typename Iterator::pointer;
		using typename Iterator::const_pointer;
		using typename Iterator::reference;
		using typename Iterator::const_reference;
		using typename Iterator::difference_type;

	protected:
		Iterator _base;

	public:
		ft_reverse_iterator() : _base() {}
		explict ft_reverse_iterator(Iterator const &it) : _base(it) {}
		ft_reverse_iterator(ft_reverse_iterator const &other): _base(other.base()) {}
		
		Iterator base() const { return _base; }

		/*
		** Assignment operators
		*/
		ft_reverse_iterator &operator=(ft_reverse_iterator const &other)
		{
			if (reinterpret_cast<const void *>(this) == reinterpret_cast<const void *>(&other))
				return *this;
			this->_base = other.base();
			return *this;
		}
		
		/*
		** Member and pointer operators
		*/
		value_type &operator*() { return *this->_pointer; };
		value_type *operator->() { return this->_pointer; };

		/*
		** Arithmetic operators
		*/
		ft_reverse_iterator operator++(int)
		{
			ft_reverse_iterator tmp(*this);
			tmp._pointer--;
			return tmp;
		}
		Iterator &operator++() { return this->Iterator::operator--(); }
		ft_reverse_iterator operator--(int)
		{
			ft_reverse_iterator tmp(*this);
			tmp._pointer++;
			return tmp;
		}
		Iterator &operator--()
		{
			return this->Iterator::operator++();
		}
		ft_reverse_iterator	operator+ (difference_type n) const
		{
			return ft_reverse_iterator(this->_base.operator-(n));
		};
		ft_reverse_iterator	operator- (difference_type n) const
		{
			return ft_reverse_iterator(this->_base.operator+(n));
		};
		difference_type		operator-(const ft_reverse_iterator &other)
		{
			return other.base().operator-(this->_base);
		};
	};

	template <class Iterator>
	size_t	distance(Iterator first, Iterator last)
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