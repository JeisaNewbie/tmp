/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:22:55 by ahkiler           #+#    #+#             */
/*   Updated: 2023/05/27 11:38:33 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
 #define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( const std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm& copy );
	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& copy );
	virtual void execute( Bureaucrat const & executor ) const;
	~ShrubberyCreationForm();
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