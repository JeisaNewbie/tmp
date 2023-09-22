/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:58:27 by ahkiler           #+#    #+#             */
/*   Updated: 2023/09/22 15:00:32 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat a("hwang", 71);
	Bureaucrat b("park", 24);
	Bureaucrat d("je", 100);
	ShrubberyCreationForm s("Home");
	RobotomyRequestForm r("robo");
	PresidentialPardonForm p("pardon");

	std::cout<<"-------------Shrubbery-----------\n";
	d.signForm(s);
	d.executeForm(s);

	std::cout<<"-------------robo-----------\n";
	a.signForm(r);
	a.executeForm(r);

	std::cout<<"-------------robo after increase 40-----------\n";
	a.increaseG(40);
	a.executeForm(r);

	std::cout<<"-------------Presidential-----------\n";
	b.signForm(p);
	b.executeForm(p);

	std::cout<<"-------------Presidential after increase 20-----------\n";
	b.increaseG(20);
	b.executeForm(p);
}