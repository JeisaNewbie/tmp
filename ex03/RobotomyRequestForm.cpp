/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:36:09 by ahkiler           #+#    #+#             */
/*   Updated: 2023/05/27 20:03:07 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): AForm("Default", 72, 45)
{
	std::cout<<"RobotomyRequestForm Default Constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target ): AForm(target, 72, 45)
{
	std::cout<<"RobotomyRequestForm Default Constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ): AForm(copy.getName(), 72, 45)
{
	std::cout<<"RobotomyRequestForm Copy Constructor called"<<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& copy )
{
	setName(copy.getName());
	return (*this);
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	if (this->getSign() != 1)
		throw RobotomyRequestForm::GradeTooLowException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw RobotomyRequestForm::ExecuteGradeTooLowException();
	srand((unsigned int)time(NULL));
	if (rand() % 2)
		std::cout<<this->getName()<<" has been robotomized"<<std::endl;
	else
		std::cout<<this->getName()<<" has not been robotomized"<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout<<"RobotomyRequestForm Default Destructor called"<<std::endl;
}