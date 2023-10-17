/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:34:55 by jhwang2           #+#    #+#             */
/*   Updated: 2023/07/25 16:49:03 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <utility>
#include <stack>

template <typename T>
class	MutantStack: public	std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator	iterator;
	MutantStack ( void ): std::stack<T>()
	{
		std::cout<<"MutantStack Constructor called"<<std::endl;
	}
	~ MutantStack ( void )
	{
		std::cout<<"MutantStack Destructor called"<<std::endl;
	}
	std::stack<T>	&operator=( const std::stack<T> &copy )
	{
		if (*this != copy)
			*this = copy;
		return (*this);
	}
	iterator	begin (void) {return (this->c.begin ());}
	iterator	end (void) {return (this->c.end());}
};

#endif