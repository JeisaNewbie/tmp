/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:44:01 by jhwang2           #+#    #+#             */
/*   Updated: 2023/10/20 20:09:28 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void )
{
}

RPN::RPN( std::string str ): str(str)
{
}

RPN::~RPN( void )
{
}

RPN::RPN( const RPN& copy )
{

}
RPN& RPN::operator=( const RPN& copy )
{

}

int	RPN::check_error( void )
{
	std::string::iterator	it = this->str.begin();
	std::string::iterator	ite = this->str.end();

	if (*(ite - 1) == ' ')
		return (1);
	for (int i = 0; it != ite; it++)
	{
		if (i % 2)
		{
			if (*it != ' ')
				return (1);
		}
		else
		{
			if (!('0' <= *it && *it <= '9') && *it != '+' && *it != '-' && *it != '*' && *it != '/')
				return (1);
		}
		i++;
	}
	return (0);
}

void	RPN::calc_num( std::string::iterator it )
{
	if (this->num.size() < 2)
		throw InvalidArgs();

	int	result = 0;

	if (*it == '+')
	{
		result = this->num.top();
		this->num.pop();
		result += this->num.top();
		this->num.pop();
		this->num.push(result);
	}
	else if (*it == '-')
	{
		result = this->num.top();
		this->num.pop();
		result = this->num.top() - result;
		this->num.pop();
		this->num.push(result);
	}
	else if (*it == '*')
	{
		result = this->num.top();
		this->num.pop();
		result *= this->num.top();
		this->num.pop();
		this->num.push(result);
	}
	else if (*it == '/')
	{
		result = this->num.top();
		this->num.pop();
		result = this->num.top() / result;
		this->num.pop();
		this->num.push(result);
	}
}

void	RPN::init_args( void )
{
	if (this->check_error())
		throw InvalidArgs();

	std::string::iterator	it = this->str.begin();
	std::string::iterator	ite = this->str.end();

	for (int i = 0; it != ite; it++)
	{
		if (i % 2)
		{
			i++;
			continue ;
		}
		if (('0' <= *it && *it <= '9'))
			this->num.push(*it - '0');
		else
			this->calc_num(it);
		i++;
	}
	if (this->num.size() > 1)
		throw InvalidArgs();
	std::cout<<this->num.top();
	return ;
}