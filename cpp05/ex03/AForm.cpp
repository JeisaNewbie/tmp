/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:50:14 by ahkiler           #+#    #+#             */
/*   Updated: 2023/09/17 16:07:53 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

std::ostream& operator<<( std::ostream& os, const AForm& copy )
{
	os<<copy.getName()<<", sign "<<copy.getSign()<<", grade_to_sign "<<copy.getGradeToSign()<<", grade_to_execute "<<copy.getGradeToExecute()<<".\n";
	return (os);
}

AForm::AForm( void ): name("Default"), grade_to_sign(75), grade_to_execute(75)
{
	// std::cout<<"AForm Default Constructor called"<<std::endl;
	sign = 0;
}
AForm::AForm( const std::string& name, int grade_to_sign, int grade_to_execute): name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	// std::cout<<"AForm Default Constructor called"<<std::endl;
	try
	{
		if (getGradeToSign() < 1 || getGradeToExecute() < 1)
			throw AForm::GradeTooHighException();
		else if (getGradeToSign() > 150 || getGradeToExecute() > 150)
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	sign = 0;
}

AForm::AForm( const AForm& copy ):name(copy.getName()), grade_to_sign(copy.getGradeToSign()), grade_to_execute(copy.getGradeToExecute())
{
	// std::cout<<"AForm Copy Constructor called"<<std::endl;
	sign = 0;
}

AForm& AForm::operator=( const AForm& copy )
{
	std::string *tmp_s = const_cast<std::string *>(&name);
	int *tmp_sign = const_cast<int *>(&grade_to_sign);
	int *tmp_execute = const_cast<int *>(&grade_to_execute);

	*tmp_s = copy.getName();
	this->sign = copy.getSign();
	*tmp_sign = copy.getGradeToSign();
	*tmp_execute = copy.getGradeToExecute();
	return (*this);
}

void AForm::beSigned( const Bureaucrat& copy )
{
	if (copy.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	sign = 1;
}

const std::string& AForm::getName ( void ) const
{
	return (this->name);
}

void AForm::setName ( const std::string name )
{
	std::string *tmp = const_cast<std::string *>(&this->name);
	*tmp = name;
}

const bool& AForm::getSign ( void ) const
{
	return (this->sign);
}

const int& AForm::getGradeToSign( void ) const
{
	return (this->grade_to_sign);
}

const int& AForm::getGradeToExecute( void ) const
{
	return (this->grade_to_execute);
}

AForm::~AForm( void )
{
	// std::cout<<"AForm Default Destructor called"<<std::endl;
}