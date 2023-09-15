/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:49:00 by ahkiler           #+#    #+#             */
/*   Updated: 2023/05/28 15:28:29 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
 #define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

namespace FORM
{
	enum
	{
		SHRUBBERYCREATIONFORM=1,
		ROBOTOMYREQUESTFORM=2,
		PRESIDENTIALPARDONFORM=3
	};
}

class Intern
{
public:
	Intern( void );
	Intern( const Intern& copy );
	Intern& operator=( const Intern& copy );
	AForm* makeForm( const std::string& name, const std::string& target );
	int compare_str( const std::string& name );
	~Intern( void );
};

Intern::Intern( void )
{
	std::cout<<"Intern Default Constructor called"<<std::endl;
}

Intern::Intern( const Intern& copy )
{
	std::cout<<"Intern Default Copy Constructor called"<<std::endl;
}

Intern& Intern::operator=( const Intern& copy )
{
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
	std::cout<<"Intern Default Destructor called"<<std::endl;
}

#endif