/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:24:02 by ahkiler           #+#    #+#             */
/*   Updated: 2023/05/27 11:39:09 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	if (this->getSign() != 1)
		throw GradeTooLowException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw ExecuteGradeTooLowException();
	std::ofstream	open_f(this->getName() + "_shrubbery");
	std::string tree = "......................             .        ......\n"
						"...........#/&&%*%&&(#%%%%#/&(@(,#  *..   . ......\n"
						".... ... /&%#%##@#%#&(%#%#&%(&&*%,@%,@/(/.... ....\n"
						"#(@&&&%&&&(&&/#&%&&##/(%%@%%&&&&&&(% ..  ....\n"
						"......,, .#&%,@ ,@&%(&# , &&*@@*&@#%%&@&%&/%......\n"
						".......... #. & // /%@%@%@&@ %@#.//&&%,#*@&.......\n"
						".............. .  .   @@@           ..............\n"
						"..............       @ @@%              . ........\n"
						".............       /@@              ... .........\n"
						"..............        @              .............\n"
						"...,,....   .,,,,,,,,,@@.,,,,,,,,.  ............ .\n"
						"***************,,,,,,,@@,,,,,,,,,***/**///////////\n"
						"#((###(##(##(#(((((((/(#(((((//((((#/(##(##(##(#(#\n"
						"#((((#/#((((((((((//((#(((/(#(#((((/((####((##/(((";
	if (open_f.is_open())
		open_f<<tree;
}

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm("Default", 145, 137)
{
	std::cout<<"ShrubberyCreationForm Default Constructor called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ): AForm(target, 145, 137)
{
	std::cout<<"ShrubberyCreationForm Default Constructor called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ): AForm(copy.getName(), 145, 137)
{
	std::cout<<"ShrubberyCreationForm Default Copy Constructor called"<<std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& copy )
{
	setName(copy.getName());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout<<"ShrubberyCreationForm Default Destructor called"<<std::endl;
}