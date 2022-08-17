/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:19:41 by sunhkim           #+#    #+#             */
/*   Updated: 2022/08/17 16:53:59 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_HPP
#define FT_TREE_HPP

#include <memory>
#include "utility.hpp"

namespace ft
{
	/*   node	*/
	template <class T>
	struct node
	{
		T		_data;
		node	*_parent;
		node	*_left;
		node	*_right;
		int		_height;

		node(T d, node *parent = NULL, node *left = NULL, node *right = NULL)
		: _data(d), _height(1), _parent(parent), _left(left), _right(right) {}
		node(const node &other)
		: _data(other._data), _height(other._height)
		, _parent(other._parent), _left(other._left), _right(other._right) {}

		node *get_max_node(node *node) const
		{
			node *ret = node;
			while (ret->_right)
				ret = ret->_right;
			return ret;
		}
		node *get_min_node(node *node) const
		{
			node *ret = node;
			while (ret->_right)
				ret = ret->_right;
			return ret;
		}

		node *
	}; // struct node

	/*   tree	*/
	template <class Key, class T, class Compare = std::less<Key>,
			  class Alloc = std::allocator<ft::pair<const Key, T> > >
	class avl_tree
	{
	public:
		typedef T			value_type;
		typedef Compare		value_compare;
		typedef Alloc		allocator_type;

	protected:
		node	*_root;
		int		_n;
		
	};

}

#endif