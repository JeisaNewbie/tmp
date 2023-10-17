/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:57:48 by jhwang2           #+#    #+#             */
/*   Updated: 2023/10/17 14:40:26 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span () : arr(0)
{
	// std::cout<<"Span Default Constructor called"<<std::endl;
	this->it = 0;
}

Span::Span ( unsigned int num ) : arr(num)
{
	// std::cout<<"Span Constructor called"<<std::endl;
	this->arr.clear ();
	this->it = 0;
}

Span::~Span ()
{
	// std::cout<<"Span Destructor called"<<std::endl;
}

void	Span::addNumber( unsigned int num )
{
	std::vector<unsigned int>::iterator	tmp_it;
	tmp_it = std::find (this->arr.begin (), this->arr.end (), num);
	if (tmp_it != this->arr.end ())
		throw ExistingValue ();
	this->arr.push_back (num);
	this->it++;
	if (this->arr.size () == this->arr.capacity ())
	{
		this->arr.push_back (num);
		this->arr.erase (this->arr.begin () + it, this->arr.end ());
	}
}

void	Span::addNumbers( int nums )
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < nums; i++)
		addNumber (rand());
}

long	Span::shortestSpan()
{
	if (this->arr.size () < 2)
		throw NoValue ();

	std::vector<unsigned int>	tmp (this->arr);
	long						shortest = LONG_MAX;

	std::sort (tmp.begin (), tmp.end ());

	for (std::vector<unsigned int>::iterator it = tmp.begin (); it != tmp.end (); it++)
	{
		if (shortest > *(it + 1) - *it)
			shortest = *(it + 1) - *it;
	}
	return (shortest);
}

long	Span::longestSpan()
{
	if (this->arr.size () < 2)
		throw NoValue ();
	std::pair<std::vector<unsigned int>::iterator, std::vector<unsigned int>::iterator>	tmp;
	tmp = std::minmax_element (this->arr.begin (), this->arr.end ());
	return (*tmp.second - *tmp.first);
}
