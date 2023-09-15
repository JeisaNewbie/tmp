/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:58:27 by ahkiler           #+#    #+#             */
/*   Updated: 2023/05/26 14:28:28 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat a;
	Bureaucrat b("park", 0);
	Bureaucrat c("hwang", 151);
	Bureaucrat d("je", 1);

	a = d;
	std::cout<<a.getName()<<std::endl;
	std::cout<<d.getName()<<std::endl;

	std::cout<<a.getGrade()<<std::endl;
	std::cout<<d.getGrade()<<std::endl;

	a.decreaseG (20);
	std::cout<<a.getGrade()<<std::endl;
	std::cout<<d.getGrade()<<std::endl;

	d.decreaseG (50);
	std::cout<<a.getGrade()<<std::endl;
	std::cout<<d.getGrade()<<std::endl;

	a.increaseG (1);
	d.increaseG (1);
	std::cout<<a.getGrade()<<std::endl;
	std::cout<<d.getGrade()<<std::endl;

	std::cout<<a<<std::endl;
	std::cout<<d<<std::endl;
}