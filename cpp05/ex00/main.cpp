/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:58:27 by ahkiler           #+#    #+#             */
/*   Updated: 2023/09/22 14:34:32 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat a;
	Bureaucrat b("park", 0);
	Bureaucrat c("hwang", 151);
	Bureaucrat d("je", 1);
	Bureaucrat e;

	a = d;
	std::cout<<"-----------name----------\n";
	std::cout<<a.getName()<<std::endl;
	std::cout<<d.getName()<<std::endl;
	std::cout<<e.getName()<<std::endl;

	std::cout<<"-----------grade----------\n";
	std::cout<<a.getGrade()<<std::endl;
	std::cout<<d.getGrade()<<std::endl;
	std::cout<<e.getGrade()<<std::endl;

	std::cout<<"-----------grade after decrease a 20----------\n";
	a.decreaseG (20);
	std::cout<<"a: "<<a.getGrade()<<std::endl;
	std::cout<<"d: "<<d.getGrade()<<std::endl;

	std::cout<<"-----------grade after decrease d 50----------\n";
	d.decreaseG (50);
	std::cout<<"a: "<<a.getGrade()<<std::endl;
	std::cout<<"d: "<<d.getGrade()<<std::endl;

	std::cout<<"-----------grade after increase a and d 1----------\n";
	a.increaseG (1);
	d.increaseG (1);
	std::cout<<"a: "<<a.getGrade()<<std::endl;
	std::cout<<"d: "<<d.getGrade()<<std::endl;

	std::cout<<"-----------grade after increase a and d 1----------\n";
	a.increaseG (20);
	d.decreaseG (101);
	std::cout<<"a: "<<a.getGrade()<<std::endl;
	std::cout<<"d: "<<d.getGrade()<<std::endl;

	std::cout<<"-----------final----------\n";
	std::cout<<a<<std::endl;
	std::cout<<d<<std::endl;
}