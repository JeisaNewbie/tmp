/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:35:05 by ahkiler           #+#    #+#             */
/*   Updated: 2023/05/27 20:12:23 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
 #define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( const std::string target );
	RobotomyRequestForm( const RobotomyRequestForm& copy );
	RobotomyRequestForm& operator=( const RobotomyRequestForm& copy );
	virtual void execute( Bureaucrat const & executor ) const;
	~RobotomyRequestForm( void );
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what( void ) const throw() {return ("Not Signed");};
	};
	class ExecuteGradeTooLowException: public std::exception
	{
		public:
			virtual const char* what( void ) const throw() {return ("Execute Grade Too Low");};
	};
};

#endif