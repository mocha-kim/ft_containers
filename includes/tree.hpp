/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:19:41 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/05 19:44:40 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_HPP
#define FT_TREE_HPP

#include <memory>
#include "utility.hpp"
#include "algorithm.hpp"

namespace ft
{
	/*   node	*/
	template <class T>
	struct tree_node
	{
		T					_data;
		tree_node			*_parent;
		tree_node			*_left;
		tree_node			*_right;
		int					_height;
		int					_balance;

		tree_node() : _parent(NULL), _left(NULL), _right(NULL)
		{}
		tree_node(const T &d) : _data(d)
		{}
		tree_node(const T &d, const int h)
		: _data(d), _parent(NULL), _left(NULL), _right(NULL)
		, _height(h), _balance(0)
		{}
		tree_node(const tree_node &other)
		: _data(other._data), _parent(other._parent), _left(other._left), _right(other._right)
		, _height(other._height), _balance(0)
		{}
	}; // struct node

	/*   tree	*/
	template <class T, class Compare, class Alloc>
	class avl_tree
	{
	public:
		typedef T														value_type;
        typedef Compare													key_compare;
		typedef typename Alloc::template rebind<tree_node<T> >::other	allocator_type;
		typedef typename allocator_type::size_type						size_type;
		typedef tree_node<T>											*node_pointer;

	private:
		node_pointer	_root;
		node_pointer	_end;
		allocator_type	_allocator;
		key_compare		_compare;
		size_type		_size;

	public:
		/*
		** Constructors, Distructor
		*/
		avl_tree(const allocator_type& alloc = allocator_type(), const key_compare& cmp = key_compare())
		: _root(NULL), _end(NULL), _allocator(alloc), _compare(cmp), _size(0)
		{
			_end = _allocator.allocate(1);
			_allocator.construct(_end);
		}
		~avl_tree()
		{
			clear();
			_allocator.deallocate(_end, 1);
			_end = NULL;
		}
		
		/*
		** Capacity
		*/
		size_type size() const { return _size; }
		size_type max_size() const { return _allocator.max_size(); }
		allocator_type get_allocator() const { return this->_allocator; }
		node_pointer get_end() const { return _end; }
		node_pointer get_min(node_pointer node = NULL) const
		{
			node_pointer tmp = node;
			if (!tmp)
			{
				if (_size)
					tmp = _root;
				else
					return _end;
			}
			while (tmp && tmp->_left)
				tmp = tmp->_left;
			return tmp;
		}
		node_pointer get_max(node_pointer node = NULL) const
		{
			node_pointer tmp = node;
			if (!tmp)
				tmp = _root;
			while (tmp && tmp->_right)
				tmp = tmp->_right;
			return tmp;
		}
		node_pointer lower_bound(const value_type &data) const
		{
			node_pointer node = get_min();
			while (node != _end)
			{
				if (!_compare(node->_data.first, data.first))
					return (node);
				node = _find_next_node(node);
			}
			return _end;
		}
		node_pointer upper_bound(const value_type& data) const
		{
			node_pointer node = get_min();
			while (node != _end)
			{
				if (_compare(data.first, node->_data.first))
					return (node);
				node = _find_next_node(node);
			}
			return _end;
		}
		node_pointer find(const value_type &data) const
		{
			return _find_node(data, _root);
		}

		/*
		** Modifiers
		*/
		void insert(const value_type data)
		{
			_insert(data, _root, _end);
			_end->_left = _root;
			_root->_parent = _end;
		}
		void swap(avl_tree &other)
		{
			ft::swap(_root, other._root);
			ft::swap(_end, other._end);
			ft::swap(_allocator, other._allocator);
			ft::swap(_compare, other._compare);
			ft::swap(_size, other._size);
		}
		void clear()
		{
			_clear(_root);
			_size = 0;
		}
		void erase(const value_type &data)
		{
			_erase(_root, data);
			_end->_left = _root;
			if (_root)
				_root->_parent = _end;
		}

	private:
		/*
		** Finders
		*/

		node_pointer _find_node(const value_type &data, node_pointer node) const
		{
			if (!node || node == _end)
				return (_end);
			if (data.first == node->_data.first)
				return (node);
			if (_compare(data.first, node->_data.first))
				return _find_node(data, node->_left);
			else
				return _find_node(data, node->_right);
		}
		node_pointer _find_next_node(node_pointer node) const
		{
			node_pointer tmp = node;
			node_pointer parent = node->_parent;
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

		/*
		** Modifiers
		*/
		void _erase(node_pointer &node, const value_type &data)
		{
			if (!node)
				return;
			if (node->_data.first == data.first)
			{
				if (!node->_left || !node->_right)
				{
					node_pointer  tmp;
					if (node->_right)
						tmp = node->_right;
					else
						tmp = node->_left;
					if (tmp)
						tmp->_parent = node->_parent;
					_allocator.deallocate(node, 1);
					node = tmp;
					_size--;
					return;
				}
				else
				{
					if (node->_left->_height > node->_right->_height)
					{
						value_type value(get_max(node->_left)->_data.first);
						_allocator.construct(node, value);
						_erase(node->_left, value);
					}
					else
					{
						value_type value(get_min(node->_right)->_data);
						_allocator.construct(node, value);
						_erase(node->_right, value);
					}
				}
			}
			else if (_compare(data.first, node->_data.first))
				_erase(node->_left, data);
			else
				_erase(node->_right, data);
			_update_node_info(node);
			_balance(node);
		}
		void _insert(const value_type &data, node_pointer &node, node_pointer &parent)
		{
			if (!node)
			{
				node = _allocator.allocate(1);
				_allocator.construct(node, data, 0);
				node->_parent = parent;
				_size++;
				return;
			}
			if (_compare(data.first, node->_data.first))
				_insert(data, node->_left, node);
			else
				_insert(data, node->_right, node);
			_update_node_info(node);
			_balance(node);
		}
		void _clear(node_pointer &node)
		{
			if (node)
			{
				_clear(node->_left);
				_clear(node->_right);
				_allocator.deallocate(node, 1);
				node = NULL;
			}
		}

		/*
		** avl tree balance
		*/
		void _update_node_info(node_pointer node)
		{
			int	left_height = node->_left ? node->_left->_height : -1;
			int	right_height = node->_right ? node->_right->_height : -1;
			node->_height = 1 + ((left_height > right_height) ? left_height : right_height);
			node->_balance = right_height - left_height;
		}
		void _balance(node_pointer &node)
		{
			if (node->_balance < -1)
			{
				if (node->_left->_balance > 0)	// LRC
				{
					_rotate_left(node->_left);
					_rotate_right(node);
				}
				else							// LLC
					_rotate_right(node);
			}
			else if (node->_balance > 1)
			{
				if (node->_right->_balance < 0)	// RLC
				{
					_rotate_right(node->_right);
					_rotate_left(node);
				}
				else							// RRC
					_rotate_left(node);
			}
		}
		void _rotate_right(node_pointer &z)
		{
			node_pointer parent = z->_parent;
			node_pointer y = z->_left;
			node_pointer subtree = y->_right;
			
			y->_right = z;
			y->_parent = parent;
			z->_left = subtree;
			z->_parent = y;
			if (subtree)
				subtree->_parent = z;
			z = y;
			
			_update_node_info(z->_right);
			_update_node_info(z);
		}
		void _rotate_left(node_pointer &z)
		{
			node_pointer parent = z->_parent;
			node_pointer y = z->_right;
			node_pointer subtree = y->_left;

			y->_left = z;
			y->_parent = parent;
			z->_right = subtree;
			z->_parent = y;
			if (subtree)
				subtree->_parent = z;
			z = y;

			_update_node_info(z->_left);
			_update_node_info(z);
		}
	};
}

#endif