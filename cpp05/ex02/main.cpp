/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:58:27 by ahkiler           #+#    #+#             */
/*   Updated: 2023/05/27 20:24:32 by ahkiler          ###   ########.fr       */
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

	d.signForm(s);
	d.executeForm(s);

	a.signForm(r);
	a.executeForm(r);

	a.increaseG(40);
	a.executeForm(r);

	b.signForm(p);
	b.executeForm(p);

	b.increaseG(20);
	b.executeForm(p);
}