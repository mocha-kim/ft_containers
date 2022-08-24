/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:02:03 by sunhkim           #+#    #+#             */
/*   Updated: 2022/08/24 22:34:45 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_MAP_ITERATOR_HPP
#define _FT_MAP_ITERATOR_HPP

#include <cstddef>
#include "iterator.hpp"
#include "tree.hpp"

namespace ft
{
	template <class T>
	class map_iterator
	{
	public:
		typedef typename iterator_traits<T>::value_type			value_type;
		typedef typename iterator_traits<T>::difference_type	difference_type;
		typedef typename iterator_traits<T>::pointer			pointer;
		typedef typename iterator_traits<T>::reference			reference;
		typedef	std::bidirectional_iterator_tag					iterator_category;
		typedef tree_node<T>	*node_pointer;

	protected:
		node_pointer _node;

	public:
		map_iterator() : _node(NULL) {}
		explicit map_iterator(node_pointer node) : _node(node) {}
		template <class T>
		map_iterator (const map_iterator<T>& other) : node(other._node) {}
		node_pointer base() const { return _node; }
		reference operator*() const { return _node->_data; }
		pointer operator->() const { return &(_node->_data); }
		map_iterator& operator++()
		{
			_node = _find_next_node();
			return (*this);
		}
		map_iterator operator++(int)
		{
			map_iterator tmp(*this);
			++(*this);
			return (tmp);
		}
		map_iterator& operator--()
		{
			_node = _find_pre_node();
			return (*this);
		}
		map_iterator operator--(int)
		{
			map_iterator tmp(*this);
			--(*this);
			return (tmp);
		}
	private:
		node_pointer _find_next_node()
		{
			node_pointer parent = _node->_parent;
			node_pointer tmp = _node;
			if (tmp->_right)
			{
				tmp = tmp->_right;
				while (tmp->_left)
					tmp = tmp->_left;
				return tmp;
			}
			else
			{
				while (parent && tmp == parent->_right)
				{
					tmp = parent;
					parent = tmp->_parent;
				}
				return parent;
			}
		}
		node_pointer _find_pre_node()
		{
			node_pointer parent = _node->_parent;
			node_pointer tmp = _node;
			if (tmp->_left)
			{
				tmp = tmp->_left;
				while (tmp->_right)
					tmp = tmp->_right;
				return tmp;
			}
			else
			{
				while (parent && tmp == parent->_left)
				{
					tmp = parent;
					parent = tmp->_parent;
				}
				return parent;
			}
		}
	};
	
	template <class T>
	bool operator== (const map_iterator<T>& lhs, const map_iterator<T>& rhs) { return (lhs.base() == rhs.base()); }
	template <class T>
	bool operator!= (const map_iterator<T>& lhs, const map_iterator<T>& rhs) { return (lhs.base() != rhs.base()); }
}

#endif