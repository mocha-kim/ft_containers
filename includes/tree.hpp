/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:19:41 by sunhkim           #+#    #+#             */
/*   Updated: 2022/08/09 22:54:11 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_HPP
#define FT_TREE_HPP

#include <memory>

namespace ft
{
	template <class T>
	struct node
	{
		T		data;
		int		height;
		node	*left;
		node	*right;

		node(T d) : data(d), height(1), left(NULL), right(NULL) {}
	};
	
	template <class T, class Compare, class Alloc = std::allocator<T> >
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