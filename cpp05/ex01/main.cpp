/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:58:27 by ahkiler           #+#    #+#             */
/*   Updated: 2023/09/22 14:48:16 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat a("hwang", 100);
	Bureaucrat d("je", 1);
	Form fa;
	Form fb("fb", 0, 151);
	Form fc("fc", 151, 1);
	Form fd("fd", 10, 1);

	fa = fd;
	std::cout<<"-----------------------------\n";
	std::cout<<fa.getName()<<std::endl;
	std::cout<<fa.getSign()<<std::endl;
	std::cout<<fa.getGradeToSign()<<std::endl;
	std::cout<<fa.getGradeToExecute()<<std::endl;
	std::cout<<"------------------------------\n";

	a.signForm(fd);
	std::cout<<fd<<std::endl;
	d.signForm(fd);

	std::cout<<fd<<std::endl;
}