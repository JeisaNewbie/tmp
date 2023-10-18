/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:04:15 by ahkiler           #+#    #+#             */
/*   Updated: 2023/10/17 19:21:04 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
 #define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <utility>
#include <climits>

#define	DEFAULT_LENGTH	10

class NoValue: public std::exception
{
	virtual const char* what( void ) const throw() {return ("Exeption: No Value");};
};

class ExistingValue: public std::exception
{
	virtual const char* what( void ) const throw() {return ("Exeption: Existing Value");};
};

class Span
{
private:
	std::vector<unsigned int>	arr;
	unsigned int				it;
	Span ();
public:
	Span ( unsigned int num );
	~Span ();
	void	addNumber( unsigned int num );
	void	addNumbers( int nums );
	long	shortestSpan();
	long	longestSpan();
};

#endif