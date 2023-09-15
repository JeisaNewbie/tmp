/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:29:45 by ahkiler           #+#    #+#             */
/*   Updated: 2023/08/21 17:40:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
 #define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	const int grade_to_sign;
	const int grade_to_execute;
	bool sign;
public:
	Form();
	Form( const std::string& name, int grade_to_sign, int grade_to_execute);
	Form( const Form& copy );
	~Form();
	Form& operator=( const Form& copy );
	void beSigned( const Bureaucrat& copy );
	const std::string& getName () const;
	const bool& getSign () const;
	const int& getGradeToSign() const;
	const int& getGradeToExecute() const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what( void ) const throw() {return ("Form: Grade Too High");};
	};
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what( void ) const throw() {return ("Form: Grade Too Low");};
	};
};

std::ostream& operator<<( std::ostream& os, const Form& copy );

#endif