/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:29:45 by ahkiler           #+#    #+#             */
/*   Updated: 2023/05/27 10:20:43 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
 #define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool	sign;
	const int	grade_to_sign;
	const int	grade_to_execute;
public:
	AForm( void );
	AForm( const std::string& name, int grade_to_sign, int grade_to_execute);
	AForm( const AForm& copy );
	AForm& operator=( const AForm& copy );
	virtual void execute(Bureaucrat const & executor) const = 0;
	void beSigned( const Bureaucrat& copy );
	const std::string& getName ( void ) const;
	void setName ( const std::string name );
	const bool& getSign ( void ) const;
	const int& getGradeToSign( void ) const;
	const int& getGradeToExecute( void ) const;
	virtual ~AForm( void );

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what( void ) const throw() {return ("AForm: Grade Too High");};
	};
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what( void ) const throw() {return ("AForm: Grade Too Low");};
	};
};

std::ostream& operator<<( std::ostream& os, const AForm& copy );

#endif