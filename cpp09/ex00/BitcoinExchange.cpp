/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:15:17 by jhwang2           #+#    #+#             */
/*   Updated: 2023/10/20 20:04:52 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
	// std::cout<<"BitcoinExchange Default Constructor Called\n";
}

BitcoinExchange::BitcoinExchange( std::string input, std::string data ) :input(input), data(data)
{
	// std::cout<<"BitcoinExchange Constructor Called\n";
}

BitcoinExchange::~BitcoinExchange( void )
{
	// std::cout<<"BitcoinExchange Destructor Called\n";
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& copy )
{

}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& copy )
{

}

int	BitcoinExchange::check_error ( std::string &str )
{
	std::stringstream	ssDouble;
	std::string			pipe(" | ");
	int					i = 0;
	double				d = 0.0;

	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (i < 10)
		{
			if (i == 4 || i == 7)
			{
				if (*it != '-')
					str = "Error: Invalid Date";
			}
			else
			{
				if (!('0' <= *it && *it <= '9'))
					str = "Error: Invalid Date";
			}
		}
		else
		{
			std::string	pipe_tmp = str.substr(10, 3);
			if (pipe_tmp.compare(pipe))
				str = "Error: Invalid Format";
			ssDouble.str((str.substr(13, str.length() - 13)));
			ssDouble >> d;
			ssDouble.clear();
			if (d < 0.0)
				str = "Error: Invalid Number";
			else if (d > 1000.0)
				str = "Error: Too Large A Number";
			break ;
		}
		i++;
	}
	if (!str.compare(0, 5, "Error"))
		return (1);
	else if (i == 10 && str.length() == 10)
	{
		str = "Error: Bad Input => " + str;
		return (1);
	}
	return (0);
}

void	BitcoinExchange::init_db( void )
{
	if (!this->input.is_open() || !this->data.is_open())
	{
		throw NoFile();
		return ;
	}

	std::stringstream	ssDouble;
	int 				i = 0;
	int					i_end = 0;
	double 				d = 0.0;

	for (std::string tmp; std::getline (this->data, tmp);)
	{
		i = tmp.find(",", 0);
		i_end = tmp.length();
		ssDouble.str((tmp.substr(i + 1, i_end - i)));
		ssDouble >> d;
		ssDouble.clear();
		this->db_data.insert(std::make_pair(tmp.substr(0, i), d));
	}
}

std::pair<std::string, double>	BitcoinExchange::return_pair( std::string str )
{
	std::stringstream	ssDouble;
	int 				i = 0;
	int					i_end = 0;
	double 				d = 0.0;

	if (this->check_error(str))
		return (std::make_pair(str, -1));
	else
	{
		i = str.find("|", 0);
		i_end = str.length();
		ssDouble.str((str.substr(i + 2, i_end - i)));
		ssDouble >> d;
		ssDouble.clear();
		return (std::make_pair(str.substr(0, i - 1), d));
	}
}

int	BitcoinExchange::min_date( std::string str1, std::string str2 )
{
	std::string::iterator it_1 = str1.begin();
	std::string::iterator it_2 = str2.begin();

	for (;it_1 != str1.end();)
	{
		if (*it_1 < *it_2)
			return (1);
		else if (*it_1 > *it_2)
			return (0);
		else
		{
			it_1++;
			it_2++;
		}
	}
	return (-1);
}

double	BitcoinExchange::get_data( void )
{
	std::map<std::string, double>::iterator	it = this->db_data.find(this->db_input.first);
	if (it != this->db_data.end())
		return (this->db_input.second * it->second);
	else
	{
		std::map<std::string, double>::iterator it_tmp = this->db_data.begin();
		std::map<std::string, double>::iterator ite_tmp = this->db_data.end();
		for (; it_tmp != ite_tmp; it_tmp++)
		{
			if (it_tmp == db_data.begin() && min_date(this->db_input.first, it_tmp->first))
				return (-1.0);
			else
			{
				if(min_date(this->db_input.first, it_tmp->first))
				{
					// std::cout<<"\n"<<this->db_input.first<<" & "<<it_tmp->first<<std::endl;
					return (this->db_input.second * (--it_tmp)->second);
				}
			}
		}
		return (this->db_input.second * (--it_tmp)->second);
	}
}

void	BitcoinExchange::print_result( void )
{
	double	value_after_exchange = 0.0;
	for (std::string tmp; std::getline (this->input, tmp);)
	{
		this->db_input = return_pair(tmp);
		if (this->db_input.second == -1.0)
			std::cout<<this->db_input.first<<std::endl;
		else
		{
			value_after_exchange = get_data();
			if (value_after_exchange == -1.0)
				continue ;
			std::cout<<this->db_input.first<<" => "<<this->db_input.second<<" = ";
			std::cout<<value_after_exchange<<std::endl;
		}
	}
}
