/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:02:03 by sunhkim           #+#    #+#             */
/*   Updated: 2022/08/25 17:39:02 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_MAP_ITERATOR_HPP
#define _FT_MAP_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template <class T, class NodePointer>
	class map_iterator
	{
	public:
		typedef typename iterator_traits<T>::value_type			value_type;
		typedef typename iterator_traits<T>::difference_type	difference_type;
		typedef typename iterator_traits<T>::pointer			pointer;
		typedef typename iterator_traits<T>::reference			reference;
		typedef	std::bidirectional_iterator_tag					iterator_category;

	protected:
		NodePointer _node;

	public:
		map_iterator() : _node(NULL) {}
		explicit map_iterator(NodePointer node) : _node(node) {}
		map_iterator (const map_iterator<T, NodePointer>& other) : _node(other._node) {}
		NodePointer base() const { return _node; }
		reference operator*() const { return _node->_data; }
		pointer operator->() const { return &(_node->_data); }
		map_iterator& operator++()
		{
			_node = _find_next_node();
			return *this;
		}
		map_iterator operator++(int)
		{
			map_iterator tmp(*this);
			++(*this);
			return tmp;
		}
		map_iterator& operator--()
		{
			_node = _find_pre_node();
			return *this;
		}
		map_iterator operator--(int)
		{
			map_iterator tmp(*this);
			--(*this);
			return tmp;
		}
	private:
		NodePointer _find_next_node()
		{
			NodePointer parent = _node->_parent;
			NodePointer tmp = _node;
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
		NodePointer _find_pre_node()
		{
			NodePointer parent = _node->_parent;
			NodePointer tmp = _node;
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
	
	template <class T, class NodePointer>
	bool operator== (const map_iterator<T, NodePointer>& lhs, const map_iterator<T, NodePointer>& rhs) { return (lhs.base() == rhs.base()); }
	template <class T, class NodePointer>
	bool operator!= (const map_iterator<T, NodePointer>& lhs, const map_iterator<T, NodePointer>& rhs) { return (lhs.base() != rhs.base()); }
}

#endif