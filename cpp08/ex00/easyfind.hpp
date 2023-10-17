/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:04:15 by ahkiler           #+#    #+#             */
/*   Updated: 2023/10/17 14:32:11 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

class NoValue: public std::exception
{
	virtual const char* what( void ) const throw() {return ("No Value");};
};

template <typename T>
typename T::iterator easyfind (T &container, int value)
{
	typename T::iterator it = std::find (container.begin(), container.end(), value);
	if (it == container.end())
		throw NoValue();
	return (it);
}

#endif