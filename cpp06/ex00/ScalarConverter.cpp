/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:33:06 by ahkiler           #+#    #+#             */
/*   Updated: 2023/10/12 15:33:33 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
	// std::cout<<"ScalarConverter Default Constructor called"<<std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& copy )
{
	// std::cout<<"ScalarConverter Default Copy Constructor called"<<std::endl;
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& copy )
{
	(void)copy;
	return (*this);
}

void ScalarConverter::check_dot(char *end)
{
	if (end[0] != '.')
		throw Impossible();
	return ;
}

int ScalarConverter::check_float(char *end)
{
	if (end[0] == '\0')
		return (1);
	else if (end[strlen(end) - 1] == 'f')
		return (1);
	else if (end[strlen(end) - 1] != 'f' && !('0' <= end[strlen(end) - 1] && end[strlen(end) - 1] <= '9'))
		return (2);
	return (0);
}

void ScalarConverter::check_num(char *end)
{
	char *tmp = strdup(end);
	int	flag = check_float(end);
	int len = strlen(end);

	if (flag == 2)
	{
		throw Impossible();
		return ;
	}
	else if (flag == 1)
	{
		len -= 1;
		if (len <= 0)
			return ;
	}
	for (int i = 0; i < len; i++)
	{
		if (!('0' <= tmp[i] && tmp[i] <= '9'))
		{
			throw Impossible();
			return ;
		}
	}
	return ;
}

void ScalarConverter::convert_to_char( const std::string& copy )
{
	char to_char = 0;
	char *end;

	try
	{
		if (copy.length() == 1 && !std::isdigit(static_cast<char>(copy[0])))
			to_char = static_cast<char>(copy[0]);
		else
		{
			long check_char = std::strtol(copy.c_str(), &end, 10);
			if (check_char < -128 || check_char > 127)
				throw Impossible();
			to_char = static_cast<char>(check_char);
			if (strlen(end) != 0)
			{
				ScalarConverter::check_dot(end++);
				ScalarConverter::check_num(end);
			}
		}
		if (to_char < 33 || to_char == 127)
			throw NonDisplayable();
		std::cout<<"char: '"<<to_char<<"'"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<"char: "<< e.what() << '\n';
	}
}

void ScalarConverter::convert_to_int( const std::string& copy )
{
	char *end;
	int to_int = 0;

	try
	{
		if (copy.length() == 1 && !std::isdigit(static_cast<char>(copy[0])))
			to_int = static_cast<int>(copy[0]);
		else
		{
			long check_int = std::strtol(copy.c_str(), &end, 10);
			if (!(-2147483648 <= check_int && check_int <= 2147483647))
				throw Impossible();
			if (strlen(end) != 0)
			{
				check_dot(end++);
				check_num(end);
			}
			to_int = static_cast<int>(check_int);
		}
		std::cout<<"int: "<<to_int<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<"int: "<< e.what() << '\n';
	}
}

int ScalarConverter::check_zero( const std::string& copy)
{
	std::string::size_type n = copy.find('.', 0);
	if (n == std::string::npos)
	{
		const char *front = copy.c_str();
		char *end = NULL;
		strtod(front, &end);
		if (front != end && end[0] != '\0')
			throw Impossible();
		return (1);
	}
	else
	{
		std::string tmp = copy.substr(n);
		if (*(--tmp.end()) == '.')
			return (1);
		else if (!tmp.compare(".f"))
			return (1);
		else if (!tmp.compare(".0"))
			return (1);
		else
		{
			for (size_t i = 1; i < tmp.length(); i++)
			{
				if (tmp.at(i) != '0' && tmp.at(i) != 'f')
					return (0);
			}
			return (1);
		}
	}
}

int ScalarConverter::check_pseudo_literals( const std::string& copy )
{
	if (!copy.compare ("nan") || !copy.compare("-inf") || !copy.compare("+inf") || !copy.compare("inf"))
		return (1);
	else if (!copy.compare ("nanf") || !copy.compare("-inff") || !copy.compare("+inff") || !copy.compare("inff"))
		return (2);
	return (0);
}

void ScalarConverter::convert_to_float( const std::string& copy )
{
	char *end;
	float to_float = 0;
	int flag = 0;

	try
	{
		if (check_pseudo_literals(copy) == 1)
		{
			std::cout<<"float: "<<copy<<"f"<<std::endl;
			return ;
		}
		else if (check_pseudo_literals(copy) == 2)
		{
			std::cout<<"float: "<<copy<<std::endl;
			return ;
		}
		flag = check_zero (copy);
		if (copy.length() == 1 && !std::isdigit(static_cast<char>(copy[0])))
			to_float = static_cast<float>(copy[0]);
		else
		{
			to_float = std::strtof(copy.c_str(), &end);
			if (check_float(end) == 2 || strlen(end) > 1)
				throw Impossible();
		}
		std::cout<<"float: "<<to_float;
		if (!std::isinf(to_float) && (-1e6f < to_float && to_float < 1e6f) && flag == 1)
			std::cout<<".0";
		std::cout<<"f"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<"float: "<< e.what() << '\n';
	}
}

void ScalarConverter::convert_to_double( const std::string& copy )
{
	char *end;
	double to_double = 0;
	int flag = 0;

	try
	{
		if (check_pseudo_literals(copy) == 1)
		{
			std::cout<<"double: "<<copy<<std::endl;
			return ;
		}
		else if (check_pseudo_literals(copy) == 2)
		{
			std::cout<<"double: "<<copy.substr(0, copy.length() - 1)<<std::endl;
			return ;
		}
		flag = check_zero (copy);
		if (copy.length() == 1 && !std::isdigit(static_cast<char>(copy[0])))
			to_double = static_cast<double>(copy[0]);
		else
		{
			to_double = std::strtod(copy.c_str(), &end);
			if (check_float(end) == 2 || strlen(end) > 1)
				throw Impossible();
		}
		std::cout<<"double: "<<to_double;
		if (!std::isinf(to_double) && flag == 1 && (-1e6f < to_double && to_double < 1e6f))
			std::cout<<".0";
		std::cout<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<"double: "<< e.what() << '\n';
	}
}

void ScalarConverter::convert( const char *origin )
{
	std::string copy(origin);
	ScalarConverter::convert_to_char( copy );
	ScalarConverter::convert_to_int( copy );
	ScalarConverter::convert_to_float( copy );
	ScalarConverter::convert_to_double( copy );
}

ScalarConverter::~ScalarConverter( void )
{
	// std::cout<<"ScalarConverter Default Destructor called"<<std::endl;
}