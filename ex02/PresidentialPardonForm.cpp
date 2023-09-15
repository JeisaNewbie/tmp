/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:10:24 by ahkiler           #+#    #+#             */
/*   Updated: 2023/05/27 20:15:36 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	if (this->getSign() != 1)
		throw GradeTooLowException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw ExecuteGradeTooLowException();
	std::cout<<this->getName()<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("Default", 25, 5)
{
	std::cout<<"PresidentialPardonForm Default Constructor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target ): AForm(target, 25, 5)
{
	std::cout<<"PresidentialPardonForm Default Constructor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ): AForm(copy.getName(), 25, 5)
{
	std::cout<<"PresidentialPardonForm Default Copy Constructor called"<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& copy )
{
	setName(copy.getName());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout<<"PresidentialPardonForm Default Destructor called"<<std::endl;
}