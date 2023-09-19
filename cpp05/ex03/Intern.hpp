/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:49:00 by ahkiler           #+#    #+#             */
/*   Updated: 2023/05/28 15:28:29 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
 #define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

namespace FORM
{
	enum
	{
		SHRUBBERYCREATIONFORM=1,
		ROBOTOMYREQUESTFORM=2,
		PRESIDENTIALPARDONFORM=3
	};
}

class Intern
{
public:
	Intern( void );
	Intern( const Intern& copy );
	Intern& operator=( const Intern& copy );
	AForm* makeForm( const std::string& name, const std::string& target );
	int compare_str( const std::string& name );
	~Intern( void );
};

#endif