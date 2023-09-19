/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:03:52 by jhwang2           #+#    #+#             */
/*   Updated: 2023/09/17 16:03:54 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
	// std::cout<<"Intern Default Constructor called"<<std::endl;
}

Intern::Intern( const Intern& copy )
{
	// std::cout<<"Intern Default Copy Constructor called"<<std::endl;
	(void)copy;
}

Intern& Intern::operator=( const Intern& copy )
{
	(void)copy;
	return (*this);
}

AForm* Intern::makeForm( const std::string& name, const std::string& target )
{
	int type = this->compare_str(name);

	switch (type)
	{
	case FORM::SHRUBBERYCREATIONFORM:
		std::cout<<"Intern creates "<<name<<std::endl;
		return (new ShrubberyCreationForm(target));
	case FORM::ROBOTOMYREQUESTFORM:
		std::cout<<"Intern creates "<<name<<std::endl;
		return (new RobotomyRequestForm(target));
	case FORM::PRESIDENTIALPARDONFORM:
		std::cout<<"Intern creates "<<name<<std::endl;
		return (new PresidentialPardonForm(target));
	default:
		std::cout<<"Failed to create "<<name<<std::endl;
		return (0);
	}
}

int	Intern::compare_str( const std::string& name )
{
	if (!name.compare("ShrubberyCreationForm"))
		return (1);
	if (!name.compare("RobotomyRequestForm"))
		return (2);
	if (!name.compare("PresidentialPardonForm"))
		return (3);
	return (0);
}

Intern::~Intern( void )
{
	// std::cout<<"Intern Default Destructor called"<<std::endl;
}