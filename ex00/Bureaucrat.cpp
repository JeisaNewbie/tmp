/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:25:21 by ahkiler           #+#    #+#             */
/*   Updated: 2023/08/21 17:10:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream& operator<<( std::ostream& os, const Bureaucrat& copy )
{
	os<<copy.getName()<<", bureaucrat grade "<<copy.getGrade()<<"."<<std::endl;
	return (os);
}

Bureaucrat::Bureaucrat(): name(""), grade(0)
{
	std::cout<<"Bureaucrat Default Constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat( const std::string& name, int grade ): name(name)
{
	std::cout<<"Bureaucrat Default Constructor called"<<std::endl;
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		this->grade = grade;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Default Destructor called"<<std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy )
{
	std::cout<<"Bureaucrat Copy Constructor called"<<std::endl;
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& copy )
{
	std::string *tmp = const_cast<std::string *>(&name);
	*tmp = copy.getName();
	grade = copy.getGrade();
	return (*this);
}

const std::string& Bureaucrat::getName () const
{
	return (this->name);
}

const int& Bureaucrat::getGrade () const
{
	return (this->grade);
}

void Bureaucrat::increaseG ( int point )
{
	try
	{
		if (point < 0)
			throw std::runtime_error("Invalid number!");
		else if (grade - point < 1)
			throw std::runtime_error("Out_of_range!");
		grade -= point;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::decreaseG ( int point )
{
	try
	{
		if (point < 0)
			throw std::runtime_error("Invalid number!");
		else if (grade + point > 150)
			throw std::runtime_error("Out_of_range!");
		grade += point;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
