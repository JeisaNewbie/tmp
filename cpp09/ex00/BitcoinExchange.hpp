/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:14:38 by jhwang2           #+#    #+#             */
/*   Updated: 2023/10/20 20:04:04 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange
{
private:
	typedef	std::map<std::string, double>::iterator	iterator;
	std::ifstream					data;
	std::ifstream					input;
	std::map<std::string, double>	db_data;
	std::pair<std::string, double>	db_input;
	int								check_error( std::string &str );
	int								min_date( std::string str1, std::string str2 );
	std::pair<std::string, double>	return_pair( std::string str );
	double							get_data( void );
public:
	BitcoinExchange( void );
	BitcoinExchange( std::string input, std::string data );
	~BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange& copy );
	BitcoinExchange& operator=( const BitcoinExchange& copy );
	void		init_db( void );
	void		print_result( void );

class NoFile: public std::exception
{
	virtual const char* what( void ) const throw() {return ("Error: No such file");};
};

};

#endif