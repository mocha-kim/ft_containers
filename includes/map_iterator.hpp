/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:02:03 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/19 19:50:12 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_MAP_ITERATOR_HPP
#define _FT_MAP_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template <typename T>
	class map_iterator : public iterator_traits<tree_node<T>*>
	{

	public:
		typedef T 				value_type;
		typedef T* 				pointer;
		typedef T& 				reference;
		
		typedef tree_node<T>* 	node_pointer;

		typedef typename iterator_traits<node_pointer>::difference_type	difference_type;
		typedef std::bidirectional_iterator_tag 					iterator_category;
	
		node_pointer	_node;
	
	public:
		/*
		** Constructors, Distructor
		*/
		map_iterator() : _node(NULL) {}
		explicit map_iterator(node_pointer node) : _node(node) {}
		map_iterator(const map_iterator& other) : _node(other._node) {}
		virtual ~map_iterator() {}
		
		/*
		** Assignment operators
		*/
		map_iterator &operator=(const map_iterator &other)
		{ 
			_node = other._node; 
			return *this;
		}
		map_iterator &operator+=(int i)
		{
			while (i)
			{
				this->operator++();
				i--;
			}
			return *this;
		}
		map_iterator &operator-=(int i)
		{
			while (i)
			{
				this->operator--();
				i--;
			}
			return *this;
		}

		/*
		** Member and pointer operators
		*/
		reference operator*() const { return this->_node->_data; }
		pointer operator->() const { return &(this->_node->_data); }

		/*
		** Arithmetic operators
		*/
		map_iterator& operator++()
		{
			node_pointer next;
			if (!_node)
				return *this;
			if (_node->_right == NULL)
			{
				next = _node;
				while (next->_parent && next == next->_parent->_right)
					next = next->_parent;
				next = next->_parent;
				_node = next;
				return (*this);
			}
			next = _node->_right;
			while (next->_left)
				next = next->_left;
			_node = next;
			return *this;
		}
		map_iterator operator++(int)
		{
			map_iterator tmp(*this);
			this->operator++();
			return tmp;
		}
		map_iterator& operator--()
		{
			node_pointer tmp = _node;			
			if (!tmp)
				return *this;
			if (tmp->_left)
			{
				tmp = tmp->_left;
				while (tmp->_right != NULL)
					tmp = tmp->_right;
				this->_node = tmp;
				return (*this);
			}
			while (tmp->_parent && tmp == tmp->_parent->_left)
				tmp = tmp->_parent;
			tmp = tmp->_parent;
			_node = tmp;
			return *this;
		}
		map_iterator operator--(int)
		{
			map_iterator tmp(*this);
			this->operator--();
			return tmp;
		}
		
		/*
		** Comparison operators
		*/
		bool operator==(const map_iterator& rhs) const { return this->_node == rhs._node; }
		bool operator!=(const map_iterator& rhs) const { return this->_node != rhs._node; }
	}; // class map_iterator

	template <class T>
	class map_const_iterator
	{
	public:
		typedef T					value_type;
		typedef const value_type	&reference;
		typedef const value_type	*pointer;

		typedef tree_node<T>*	node_pointer;

		typedef typename iterator_traits<node_pointer>::difference_type	difference_type;
		typedef std::bidirectional_iterator_tag 						iterator_category;
		
		node_pointer	_node;
	
	public:
		/*
		** Constructors, Distructor
		*/
		map_const_iterator() : _node(NULL) {}
		explicit map_const_iterator(node_pointer node) : _node(node) {}
		template <class K>
		map_const_iterator(const map_iterator<K>& copy) : _node(copy._node) {}
		~map_const_iterator() {}

		/*
		** Assignment operators
		*/
		template <class K>
		map_const_iterator& operator=(const map_iterator<K>& copy)
		{ 
			this->_node = copy._node; 
			return *this; 
		}
		
		/*
		** Member and pointer operators
		*/
		reference operator*() const { return (this->_node->_data); }
		pointer operator->(void) const { return &(this->_node->_data); }
	
		/*
		** Arithmetic operators
		*/
		map_const_iterator& operator++()
		{
			node_pointer next;
			if (!_node)
				return *this;
			if (_node->_right == NULL)
			{
				next = _node;
				while (next->_parent && next == next->_parent->_right)
					next = next->_parent;
				next = next->_parent;
				_node = next;
				return (*this);
			}
			next = _node->_right;
			while (next->_left)
				next = next->_left;
			_node = next;
			return (*this);
		}
		map_const_iterator operator++(int)
		{
			map_const_iterator tmp(*this);;
			this->operator++();
			return tmp;
		}
		map_const_iterator& operator--()
		{
			node_pointer tmp = _node;			
			if (!tmp)
				return *this;
			if (tmp->_left)
			{
				tmp = tmp->_left;
				while (tmp->_right != NULL)
					tmp = tmp->_right;
				this->_node = tmp;
				return (*this);
			}
			while (tmp->_parent && tmp == tmp->_parent->_left)
				tmp = tmp->_parent;
			tmp = tmp->_parent;
			_node = tmp;
			return (*this);
		}
		map_const_iterator operator--(int)
		{
			map_const_iterator tmp(*this);
			this->operator--();
			return tmp;
		}
		
		/*
		** Comparison operators
		*/
		bool operator==(const map_const_iterator &rhs) const { return this->_node == rhs._node; }			
		bool operator!=(const map_const_iterator &rhs) const { return this->_node != rhs._node; }
	}; // class map_const_iterator
}

#endif