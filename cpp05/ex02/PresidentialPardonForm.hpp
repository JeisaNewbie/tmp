/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:09:40 by ahkiler           #+#    #+#             */
/*   Updated: 2023/05/27 20:14:28 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
 #define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( const std::string target );
	PresidentialPardonForm( const PresidentialPardonForm& copy );
	PresidentialPardonForm& operator=( const PresidentialPardonForm& copy );
	virtual void execute( Bureaucrat const & executor ) const;
	~PresidentialPardonForm( void );
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