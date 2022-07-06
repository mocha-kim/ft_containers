/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:55:57 by sunhkim           #+#    #+#             */
/*   Updated: 2022/07/06 17:17:27 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T	value_type;
		typedef Container container_type;
		typedef size_t	size_type;
	
	protected:
		container_type _container;

	public:
		explicit stack(const container_type &cont = container_type())
		: _container(cont) {};
		stack(const stack &other)
		{
			*this = other;
		};
		~stack(void) {};

		stack &operator=(const stack &other)
		{
			this->_container = other._container;
			return (*this);
		};

		bool empty(void) const
		{
			return (_container.empty());
		};
		size_type size(void) const
		{
			return (_container.size());
		};

		value_type &top(void)
		{
			return (_container.back());
		};
		const value_type &top(void) const
		{
			return (_container.back());
		};

		void push(const value_type &value)
		{
			_container.push_back(value);
		};
		void pop(void)
		{
			_container.pop_back();
		};

	private:
		template <class T, class Container>
		friend bool	operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
		template <class T, class Container>
		friend bool	operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
		template <class T, class Container>
		friend bool	operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
		template <class T, class Container>
		friend bool	operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
		template <class T, class Container>
		friend bool	operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
		template <class T, class Container>
		friend bool	operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
	};
	
	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._container == rhs._container);
	};
	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._container != rhs._container);
	};
	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._container > rhs._container);
	};
	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._container < rhs._container);
	};
	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._container >= rhs._container);
	};
	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._container <= rhs._container);
	};
}

#endif