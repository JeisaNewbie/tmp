/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:35:30 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/03 12:07:42 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main()
{
	int a_i = 1;
	int b_i = 2;
	double a_d = 1.0;
	double b_d = 2.0;

	std::cout<<"swap_before: "<<a_i<<", "<<b_i<<std::endl;
	swap(a_i, b_i);
	std::cout<<"swap_after: "<<a_i<<", "<<b_i<<std::endl;
	std::cout<<"swap_before: "<<a_d<<", "<<b_d<<std::endl;
	swap(a_i, b_i);
	std::cout<<"swap_after: "<<a_d<<", "<<b_d<<std::endl;
	std::cout<<"-------\n";
	std::cout<<"min_int: "<<min(a_i, b_i)<<std::endl;
	std::cout<<"min_double: "<<min(a_i, b_i)<<std::endl;
	std::cout<<"-------\n";
	std::cout<<"max_int: "<<max(a_i, b_i)<<std::endl;
	std::cout<<"max_double: "<<max(a_i, b_i)<<std::endl;
	std::cout<<"-------\n";

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}