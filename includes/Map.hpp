/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:56:08 by sunhkim           #+#    #+#             */
/*   Updated: 2022/07/06 17:17:20 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <memory>
#include "Functional.hpp"
#include "utility.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>,
			  class Allocator = std::allocator<std::pair<const Key, T> > >
	class map
	{
		// typedef key_type	Key
		// typedef mapped_type	T
		// typedef value_type	std::pair<const Key, T>
		// typedef size_type	Unsigned integer type (usually std::size_t)
		// typedef difference_type	Signed integer type (usually std::ptrdiff_t)
		// typedef key_compare	Compare
		// typedef allocator_type	Allocator
		// typedef reference	value_type&
		// typedef const_reference	const value_type&
		// typedef pointer    Allocator::pointer
		// typedef const_pointer    Allocator::const_pointer
		// typedef iterator	LegacyBidirectionalIterator to value_type
		// typedef const_iterator	LegacyBidirectionalIterator to const value_type
		// typedef reverse_iterator	std::reverse_iterator<iterator>
		// typedef const_reverse_iterator	std::reverse_iterator<const_iterator>

		explicit map map();
		explicit map(const Compare& comp);
		explicit map(const map& x);
		map& operator=(const map& x);
		~map();

		// member_function
		size_type size() const;
		size_type max_size() const;
		bool empty() const;
		allocator_type get_allocator() const;


		// iterator
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		
		// Modified member functions
		std::pair<iterator, bool> insert(const value_type& value);
		template< class InputIt >
		void insert( InputIt first, InputIt last );
		size_type erase(const key_type& k);
		void erase(iterator position);
		void erase(iterator first, iterator last);
		void clear();
		void swap(map& x);

		// lookup
		iterator find(const key_type& k);
		const_iterator find(const key_type& k) const;
		size_type count(const key_type& k) const;
		std::pair<iterator, iterator> equal_range(const key_type& k);
		std::pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
		iterator lower_bound(const key_type& k);
		const_iterator lower_bound(const key_type& k) const;
		iterator upper_bound(const key_type& k);
		const_iterator upper_bound(const key_type& k) const;

		std::map<Key,T,Compare,Allocator>::key_compare key_comp() const;
		std::map<Key,T,Compare,Allocator>::value_compare value_comp() const;
	};
}

#endif