/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:23:49 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/02 17:05:29 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base( void )
{
	std::cout<<"Base Default Destructor called"<<std::endl;
}

Base * generate(void)
{
	srand((unsigned int)time(NULL));
	if (rand() % 3 == 1)
	{
		A *a = new A;
		return (dynamic_cast<Base *>(a));
	}
	else if (rand() % 3 == 2)
	{
		B *b = new B;
		return (dynamic_cast<Base *>(b));
	}
	else
	{
		C *c = new C;
		return (dynamic_cast<Base *>(c));
	}
}

void identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	if (a == NULL)
	{
		B *	b = dynamic_cast<B *>(p);
		if (b == NULL)
		{
			C *c = dynamic_cast<C *>(p);
			if (c == NULL)
			{
				std::cout<<"Error: Not Matching\n";
				return ;
			}
			std::cout<<"Type of Class: C\n";
			return ;
		}
		std::cout<<"Type of Class: B\n";
		return ;
	}
	std::cout<<"Type of Class: A\n";
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout<<"Type of Class: A\n";
	}
	catch(std::bad_cast expt)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout<<"Type of Class: B\n";
		}
		catch(std::bad_cast expt)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout<<"Type of Class: C\n";
			}
			catch(std::bad_cast expt)
			{
				std::cerr << expt.what() << '\n';
			}
		}
	}
}