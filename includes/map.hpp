/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:56:08 by sunhkim           #+#    #+#             */
/*   Updated: 2022/09/05 19:55:32 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <memory>
#include <functional>
#include "tree.hpp"
#include "map_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>,
			  class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
        typedef Key			key_type;
        typedef T			mapped_type;
        typedef Compare		key_compare;
        typedef Alloc		allocator_type;

        typedef pair<const Key, T>							value_type;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;

		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;

		typedef avl_tree<value_type, key_compare, allocator_type>	tree_type;
		typedef typename tree_type::node_pointer					node_pointer;

        class value_compare : public std::binary_function<value_type, value_type, bool>
		{
            friend class map;
        protected:
            key_compare compare;
            value_compare(key_compare c) : compare(c) {}

        public:
            bool operator()(const value_type& x, const value_type& y) const
			{
                return compare(x.first, y.first);
            }
        };

		typedef ft::map_iterator<pointer, node_pointer>			iterator;
		typedef ft::map_iterator<pointer, node_pointer>			const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

	protected:

        tree_type 		_tree;
		allocator_type	_allocator;
		key_compare		_compare;

	public:
		/*
		** Constructors, Distructor
		*/
		explicit map(const key_compare& comp = key_compare(), const allocator_type &alloc = allocator_type())
		: _tree(), _allocator(alloc), _compare(comp)
		{}
		explicit map(const map& x)
		: _allocator(x._allocator), _compare(x._compare)
		{
			*this = x;
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare &comp = key_compare()
			, const allocator_type &alloc = allocator_type())
		: _tree(), _allocator(alloc), _compare(comp)
		{
			for (; first != last; first++)
				_tree.insert(*first);
		}
		~map() {}

		map &operator=(const map &x)
		{
			if (this == &x)
				return *this;

			_tree.clear();
			if (x.size())
				insert(x.begin(), x.end());
			_allocator = x._allocator;
			_compare = x._compare;
			return *this;
		}

		/*
		** Iterators
		*/	
		iterator begin() { return iterator(_tree.get_min()); }
		const_iterator begin() const { return const_iterator(_tree.get_min()); }
		iterator end() { return iterator(_tree.get_end()); }
		const_iterator end() const { return const_iterator(_tree.get_end()); }
		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		/*
		** Capacity
		*/
		bool empty() const { return _tree.size() == 0; }
		size_type size() const { return _tree.size(); }
		size_type max_size() const { return _tree.max_size(); }

		/*
		** Element access
		*/
		mapped_type &operator[] (const key_type &k)
		{
			value_type data = ft::make_pair(k, mapped_type());
			node_pointer node = _tree.find(data);
			if (!node || node == _tree.get_end())
			{
				_tree.insert(data);
				node = _tree.find(data);
			}
			return node->_data.second;
		}

		/*
		** Modifiers
		*/
		ft::pair<iterator, bool> insert(const value_type &value)
		{
			node_pointer node = _tree.find(value);
			if (!node || node == _tree.get_end())
			{
				_tree.insert(value);
				node = _tree.find(value);
				return ft::make_pair(iterator(node), true);
			}
			return ft::make_pair(iterator(node), false);
		}
		iterator insert(iterator position, const value_type &value)
		{
			static_cast<void>(position);
			node_pointer node = _tree.find(value);
			if (!node || node == _tree.get_end())
			{
				_tree.insert(value);
				node = _tree.find(value);
			}
			return iterator(node);
		}
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (; first != last; first++)
			{
				node_pointer node = _tree.find(*first);
				if (!node || node == _tree.get_end())
					_tree.insert(*first);
			}
		}
		size_type erase(const key_type &k)
		{
			node_pointer node = _tree.find(ft::make_pair(k, mapped_type()));
			if (!node || node == _tree.get_end())
				return 0;
			_tree.erase(node->_data);
			return 1;
		}
		void erase(iterator position)
		{
			node_pointer node = position.base();
			if (node)
				_tree.erase(*position);
		}
		void erase(iterator first, iterator last)
		{
			iterator target;
			for (; first != last; first++)
			{
				target = first;
				erase(target);
				if (first == iterator(_tree.get_end()))
					break;
			}
		}
		void clear() { _tree.clear(); }
		void swap(map &x)
		{
			_tree.swap(x._tree);
			ft::swap(_allocator, x._allocator);
			ft::swap(_compare, x._compare);
		}

		/*
		** Observers
		*/
		key_compare key_comp() const { return _compare; }
		value_compare value_comp() const { return value_compare(_compare); }

		/*
		** Operations
		*/
		iterator find(const key_type& k)
		{
			node_pointer node = _tree.find(ft::make_pair(k, mapped_type()));
			return iterator(node);
		}
		const_iterator find(const key_type& k) const
		{
			node_pointer node = _tree.find(ft::make_pair(k, mapped_type()));
			return const_iterator(node);
		}
		size_type count(const key_type& k) const
		{
			node_pointer node = _tree.find(ft::make_pair(k, mapped_type()));
			if (!node || node == _tree.get_end())
				return 0;
			return 1;
		}
		const_iterator lower_bound(const key_type& k) const
		{
			const_iterator ret = find(k);
			if (ret.base() == _tree.get_end())
				ret = iterator(_tree.lower_bound(ft::make_pair(k, mapped_type())));
			return ret;
		}
		iterator lower_bound(const key_type& k)
		{
			iterator ret = find(k);
			if (ret.base() == _tree.get_end())
				ret = iterator(_tree.lower_bound(ft::make_pair(k, mapped_type())));
			return ret;
		}
		const_iterator upper_bound(const key_type& k) const
		{
			const_iterator ret = find(k);
			if (ret.base() == _tree.get_end())
				ret = iterator(_tree.lower_bound(ft::make_pair(k, mapped_type())));
			else
				ret++;
			return ret;
		}
		iterator upper_bound(const key_type& k)
		{
			iterator ret = find(k);
			if (ret.base() == _tree.get_end())
				ret = iterator(_tree.lower_bound(ft::make_pair(k, mapped_type())));
			else
				ret++;
			return ret;
		}
		ft::pair<iterator, iterator> equal_range(const key_type& k)
		{
			iterator lower = lower_bound(k);
			iterator upper = upper_bound(k);
			return ft::make_pair<iterator, iterator>(lower, upper);
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
		{
			const_iterator lower = lower_bound(k);
			const_iterator upper = upper_bound(k);
			return ft::make_pair<const_iterator, const_iterator>(lower, upper);
		}

		/*
		** Allocator
		*/
		allocator_type get_allocator() const { return _allocator; }
	};
}

#endif
