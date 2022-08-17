/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:19:41 by sunhkim           #+#    #+#             */
/*   Updated: 2022/08/17 21:25:57 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_HPP
#define FT_TREE_HPP

#include <memory>
#include "utility.hpp"

namespace ft
{
	enum balance
	{
		NONE = 0,
		RIGHT = 1,
		LEFT = 2
	};

	/*   node	*/
	template <class T>
	struct tree_node
	{
		T			_data;
		tree_node	*_parent;
		tree_node	*_left;
		tree_node	*_right;
		int			_height;
		balance		_balance;

		tree_node(T d, node_pointer parent = NULL, node_pointer left = NULL, node_pointer right = NULL)
		: _data(d), _height(1), _parent(parent), _left(left), _right(right), _balance(NONE) {}
		tree_node(const tree_node &other)
		: _data(other._data), _height(other._height)
		, _parent(other._parent), _left(other._left), _right(other._right), _balance(NONE) {}
	}; // struct node

	/*   tree	*/
	template <class T, class Compare, class Alloc>
	class avl_tree
	{
	public:
		typedef T			value_type;
        typedef Compare		key_compare;
		typedef Alloc		allocator_type;
		typedef std::size_t	size_type;
		typedef tree_node<T>	*node_pointer;

	private:
		tree_node	*_root;
		tree_node	*_ptr;
		allocator_type	_allocator;
		key_compare		_compare;
		size_type		_size;

	public:
		avl_tree(const allocator_type& alloc = allocator_type(), const key_compare& cmp = key_compare())
		: _root(NULL), _ptr(NULL), _allocator(alloc), _compare(cmp), _size(0) {}
		~avl_tree()
		{
			_clear();
			_allocator.deallocate(_ptr, 1);
			_ptr = NULL;
		}
		
		size_type size() const { return _size; }
		size_type max_size() const { return _alloc.max_size(); }
		allocator_type get_allocator() const { return this->_alloc; }
		node_pointer get_ptr() const { return this->_ptr; }
		node_pointer get_min(node_pointer node = NULL) const
		{
			node_pointer tmp = node;
			if (!tmp)
				tmp = _root;
			while (tmp && tmp->left)
				tmp = tmp->left;
			return tmp;
		}
		node_pointer get_max(node_pointer node = NULL) const
		{
			node_pointer tmp = node;
			if (!tmp)
				tmp = _root;
			while (tmp && tmp->right)
				tmp = tmp->right;
			return tmp;
		}
		node_pointer lower_bound(const value_type &data)
		{
			node_pointer node = get_min();
			while (node != _ptr)
			{
				if (!_compare(node->data.first, data.first))
					return (node);
				node = successor(node);
			}
			return (_ptr);
		}
		node_pointer upper_bound(const value_type& data)
		{
			node_pointer node = get_min();
			while (node != _ptr)
			{
				if (_compare(data.first, node->data.first))
					return (node);
				node = successor(node);
			}
			return (_ptr);
		}
		void swap(avl_tree &other)
		{
			node_pointer	tmp_root = _root;
			node_pointer	tmp_ptr = _ptr;
			allocator_type	tmp_alloc = _allocator;
			key_compare		tmp_compare = _compare;
			size_type		tmp_size = _size;

			this->_root = other._root;
			this->_ptr = other._ptr;
			this->_allocator = other._alloc;
			this->_compare = other._cmp;
			this->_size = other._size;
			
			other._root = tmp_root;
			other._ptr = tmp_ptr;
			other._alloc = tmp_alloc;
			other._compare = tmp_compare;
			other._size = tmp_size;
		}
		void clear()
		{
			_clear(_root);
			_size = 0;
		}
		node_pointer find(const value_type &data)
		{
			return _find_node(data, _root);
		}
		void insert(const value_type data)
		{
			_insert(data, _root, _ptr);
			_ptr->left = _root;
			_root->parent = _ptr;
		}
		void erase(const value_type &data)
		{
			_erase(_root, data);
			_ptr->left = _root;
			if (_root)
				_root->parent = _ptr;
		}
	private:
		void _erase(node_pointer &node, const value_type &data)
		{
			if (!node)
				return ;
			if (node->data.first == data.first)
			{
				if (!node->left || !node->right)
				{
					node_pointer  tmp;
					if (node->right)
						tmp = node->right;
					else
						tmp = node->left;
					if (tmp)
						tmp->parent = node->_parent;
					_alloc.deallocate(node, 1);
					node = tmp;
					_size--;
					return ;
				}
				else
				{
					if (node->left->height > node->right->height)
					{
						value_type value(get_max(node->left)->data);
						_alloc.construct(node, value);
						_erase(node->left, value);
					}
					else
					{
						value_type value(get_min(node->right)->data);
						_alloc.construct(node, value);
						_erase(node->right, value);
					}
				}
			}
			else if (_cmp(data.first, node->data.first))
				_erase(node->left, data);
			else
				_erase(node->right, data);
			update(node);
			balance(node);
		}
		void _insert(const value_type& data, node_pointer  &node, node_pointer & parent)
		{
			if (!node)
			{
				node = _alloc.allocate(1);
				_alloc.construct(node, data, 0);
				node->parent = parent;
				_size++;
				return ;
			}
			if (_cmp(data.first, node->data.first))
				_insert(data, node->left, node);
			else
				_insert(data, node->right, node);
			update(node);
			balance(node);
		}
		node_pointer 	_find_node(const value_type& data, node_pointer & node)
		{
			if (!node || node == _ptr)
				return (_ptr);
			if (data.first == node->data.first)
				return (node);
			if (_cmp(data.first, node->data.first))
				return _find_node(data, node->left);
			else
				return _find_node(data, node->right);
		}
		node_pointer successor(node_pointer node)
		{
			node_pointer parent = node->parent;
			node_pointer tmp = node;
			if (tmp->right)
			{
				tmp = tmp->right;
				while (tmp->left)
					tmp = tmp->left;
				return tmp;
			}
			else
			{
				while (parent && tmp == parent->right)
				{
					tmp = parent;
					parent = tmp->parent;
				}
				return (parent);
			}
		}
		void _clear(node_pointer  &node)
		{
			if (node)
			{
				_clear(node->left);
				_clear(node->right);
				_alloc.deallocate(node, 1);
				node = NULL;
			}
		}
		void	update(node_pointer node)
		{
			int	left_height = node->_left ? node->_left->_height : -1;
			int	right_height = node->_right ? node->_right->_height : -1;
			node->height = 1 + ((left_height > right_height) ? left_height : right_height);
			node->balanceFactor = right_height - left_height;
		}
		void	balance(node_pointer  &node)
		{
			if (node->balanceFactor < -1)
			{
				if (node->left->balanceFactor <= 0)
					leftLeftCase(node);
				else
					leftRightCase(node);
			}
			else if (node->balanceFactor > 1)
			{
				if (node->right->balanceFactor >= 0)
					rightRightCase(node);
				else
					rightLeftCase(node);
			}
		}
		void	leftRotation(node_pointer  &node)
		{
			node_pointer 	parent = node->parent;
			node_pointer 	root = node->right;
			node->right = root->left;
			if (node->right)
				node->right->parent = node;
			node->parent = root;
			root->left = node;
			root->parent = parent;
			node = root;
			update(node->left);
			update(node);
		}		
		void	rightRotation(node_pointer  &node)
		{
			node_pointer 	parent = node->parent;
			node_pointer 	root = node->left;
			node->left = root->right;
			if (node->left)
				node->left->parent = node;
			node->parent = root;
			root->right = node;
			root->parent = parent;
			node = root;
			update(node->right);
			update(node);
		}		
		void	leftLeftCase(node_pointer  &node)
		{
			rightRotation(node);
		}
		void	leftRightCase(node_pointer  &node)
		{
			leftRotation(node->left);
			rightRotation(node);
		}
		void	rightRightCase(node_pointer  &node)
		{
			leftRotation(node);
			
		}
		void	rightLeftCase(node_pointer  &node)
		{
			rightRotation(node->right);
			leftRotation(node);
		}
	};
}

#endif