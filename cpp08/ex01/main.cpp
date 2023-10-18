/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:02:41 by ahkiler           #+#    #+#             */
/*   Updated: 2023/10/17 19:18:22 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span	tmp(20);

	try
	{
		std::cout<<tmp.longestSpan()<<std::endl;
		std::cout<<tmp.shortestSpan()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < 30; i++)
		tmp.addNumber(i);
	std::cout<<tmp.longestSpan()<<std::endl;
	std::cout<<tmp.shortestSpan()<<std::endl;
	try
	{
		tmp.addNumbers(500);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout<<tmp.longestSpan()<<std::endl;
	std::cout<<tmp.shortestSpan()<<std::endl;

	Span	tmp2(5);

	tmp2.addNumber(2);
	tmp2.addNumber(10);
	tmp2.addNumber(30);
	tmp2.addNumber(100);
	tmp2.addNumber(90);
	std::cout<<tmp2.longestSpan()<<std::endl;
	std::cout<<tmp2.shortestSpan()<<std::endl;
}