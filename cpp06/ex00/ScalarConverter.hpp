/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:20:53 by ahkiler           #+#    #+#             */
/*   Updated: 2023/09/19 15:55:16 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <iomanip>
#include <limits>

class ScalarConverter
{
private:
	static char to_char;
	static int to_int;
	static float to_float;
	static double to_double;
	ScalarConverter( void );
	~ScalarConverter( void );
	ScalarConverter( const ScalarConverter& copy );
	ScalarConverter& operator=( const ScalarConverter& copy );
public:
	static void convert( const char *origin );
	static void convert_to_char( const std::string& copy );
	static void convert_to_int( const std::string& copy );
	static void convert_to_float( const std::string& copy );
	static void convert_to_double( const std::string& copy );
	static void check_dot(char *end);
	static int check_float(char *end);
	static void check_num(char *end);
	static int check_zero( const std::string& copy);
	class NonDisplayable: public std::exception
	{
		public:
			virtual const char* what( void ) const throw() {return ("Non displayable");};
	};
	class Impossible: public std::exception
	{
		public:
			virtual const char* what( void ) const throw() {return ("impossible");};
	};
};

#endif