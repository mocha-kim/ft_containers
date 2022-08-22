/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:56:08 by sunhkim           #+#    #+#             */
/*   Updated: 2022/08/22 19:00:08 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <memory>
#include "tree.hpp"
#include "functional.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>,
			  class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
        typedef Compare				key_compare;
        typedef Key					key_type;
        typedef T					mapped_type;
        typedef Alloc				allocator_type;
        typedef pair<const Key, T>	value_type;
		typedef std::size_t			size_type;
		typedef std::ptrdiff_t		difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;

        class value_compare : public std::binary_function<value_type, value_type, bool>
		{
            friend class map;
        protected:
            key_compare _compare;
            value_compare(key_compare c) : _compare(c) {}

        public:
            bool operator()(const value_type& x, const value_type& y) const
			{
                return _compare(x.first, y.first);
            }
        };

	protected:
		typedef avl_tree<key_type, mapped_type, key_compare, allocator_type>	tree_type;

		allocator_type	_allocator;
        tree_type 		_tree;
		key_compare		_compare;

	public:
		/*
		** Constructors, Distructor
		*/
		explicit map map();
		explicit map(const key_compare& comp = key_compare(), const allocator_type &alloc = allocator_type())
		: _compare(comp), _allocator(alloc)
		{
			_tree = 
		}
		explicit map(const map& x);
		map& operator=(const map& x);
		~map();


		/*
		** Iterators
		*/	
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		// rbegin, rend

		/*
		** Capacity
		*/
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		/*
		** Element access
		*/
		// operator[]

		/*
		** Modifiers
		*/
		std::pair<iterator, bool> insert(const value_type& value);
		template< class InputIt >
		void insert( InputIt first, InputIt last );
		size_type erase(const key_type& k);
		void erase(iterator position);
		void erase(iterator first, iterator last);
		void clear();
		void swap(map& x);

		/*
		** Observers
		*/
		std::map<Key,T,Compare,Allocator>::key_compare key_comp() const;
		std::map<Key,T,Compare,Allocator>::value_compare value_comp() const;

		/*
		** Operations
		*/
		iterator find(const key_type& k);
		const_iterator find(const key_type& k) const;
		size_type count(const key_type& k) const;
		iterator lower_bound(const key_type& k);
		const_iterator lower_bound(const key_type& k) const;
		iterator upper_bound(const key_type& k);
		const_iterator upper_bound(const key_type& k) const;
		std::pair<iterator, iterator> equal_range(const key_type& k);
		std::pair<const_iterator, const_iterator> equal_range(const key_type& k) const;

		/*
		** Allocator
		*/
		allocator_type get_allocator() const;
	};
}

#endif
