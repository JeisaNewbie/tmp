/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:58:27 by ahkiler           #+#    #+#             */
/*   Updated: 2023/09/17 16:17:51 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

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

	Intern	je;
	AForm *tmp;

	tmp = je.makeForm("ShrubberyCreationFormm", "myhome");//ShrubberyCreationForm + m (fail)
	if (tmp == NULL)
	{
		std::cout<<"Error: Form doesn't exist"<<std::endl;
		return (0);
	}
	d.signForm(*tmp);
	d.executeForm(*tmp);
	delete tmp;
}