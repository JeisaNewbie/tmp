/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:15:55 by ahkiler           #+#    #+#             */
/*   Updated: 2023/08/21 17:43:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string name;
	int	grade;
public:
	Bureaucrat();
	Bureaucrat( const std::string& name, int grade );
	Bureaucrat( const Bureaucrat& copy );
	~Bureaucrat();
	Bureaucrat& operator=( const Bureaucrat& copy );
	const std::string& getName () const;
	const int& getGrade () const;
	void increaseG ( int point );
	void decreaseG ( int point );
	void signForm( Form& copy );

	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what( void ) const throw() {return ("Grade Too High");};
	};
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what( void ) const throw() {return ("Grade Too Low");};
	};
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& copy );

#endif