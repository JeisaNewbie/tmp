/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:50:14 by ahkiler           #+#    #+#             */
/*   Updated: 2023/09/22 14:44:55 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

std::ostream& operator<<( std::ostream& os, const Form& copy )
{
	os<<copy.getName()<<", sign "<<copy.getSign()<<", grade_to_sign "<<copy.getGradeToSign()<<", grade_to_execute "<<copy.getGradeToExecute()<<".\n";
	return (os);
}

Form::Form(): name("Default"), grade_to_sign(75), grade_to_execute(75)
{
	// std::cout<<"Form Default Constructor called"<<std::endl;
	sign = 0;
}

Form::Form( const std::string& name, int grade_to_sign, int grade_to_execute): name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	// std::cout<<"Form Default Constructor called"<<std::endl;
	try
	{
		if (getGradeToSign() < 1 || getGradeToExecute() < 1)
			throw Form::GradeTooHighException();
		else if (getGradeToSign() > 150 || getGradeToExecute() > 150)
			throw Form::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	sign = 0;
}

Form::Form( const Form& copy ):name(copy.getName()), grade_to_sign(copy.getGradeToSign()), grade_to_execute(copy.getGradeToExecute()), sign(copy.getSign())
{
	// std::cout<<"Form Copy Constructor called"<<std::endl;
}

Form::~Form()
{
	// std::cout<<"Form Default Destructor called"<<std::endl;
}

Form& Form::operator=( const Form& copy )
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

void Form::beSigned( const Bureaucrat& copy )
{
	if (copy.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	sign = 1;
}

const std::string& Form::getName () const
{
	return (this->name);
}

const bool& Form::getSign () const
{
	return (this->sign);
}

const int& Form::getGradeToSign() const
{
	return (this->grade_to_sign);
}

const int& Form::getGradeToExecute() const
{
	return (this->grade_to_execute);
}
