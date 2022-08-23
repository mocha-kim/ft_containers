/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:02:03 by sunhkim           #+#    #+#             */
/*   Updated: 2022/08/23 15:44:37 by sunhkim          ###   ########.fr       */
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
		template <class Iter>
		map_iterator (const map_iterator<Iter>& it) : node(it.node) {}
		nodePtr base() const{return node;}
		reference operator*() const{return node->data;}
		pointer operator->() const {return (&(node->data));}
		mapiterator& operator++()
		{
			node = successor();
			return (*this);
		}
		mapiterator operator++(int)
		{
			mapiterator tmp(*this);
			++(*this);
			return (tmp);
		}
		mapiterator& operator--()
		{
			node = predecessor();
			return (*this);
		}
		mapiterator operator--(int)
		{
			mapiterator tmp(*this);
			--(*this);
			return (tmp);
		}
	private:
		nodePtr	successor()
		{
			nodePtr	parent = node->parent;
			nodePtr	tmp = node;
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
		nodePtr	predecessor()
		{
			nodePtr	parent = node->parent;
			nodePtr	tmp = node;
			if (tmp->left)
			{
				tmp = tmp->left;
				while (tmp->right)
					tmp = tmp->right;
				return tmp;
			}
			else
			{
				while (parent && tmp == parent->left)
				{
					tmp = parent;
					parent = tmp->parent;
				}
				return (parent);
			}
		}
	};
	
	template <class It>
	bool operator== (const map_iterator<It>& lhs, const map_iterator<It>& rhs) { return (lhs.base() == rhs.base()); }
	template <class It>
	bool operator!= (const map_iterator<It>& lhs, const map_iterator<It>& rhs) { return (lhs.base() != rhs.base()); }
}

#endif