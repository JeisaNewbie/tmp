/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:44:16 by jhwang2           #+#    #+#             */
/*   Updated: 2023/10/20 20:09:02 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>

class RPN
{
private:
	std::string			str;
	std::stack<int>		num;
	int					check_error( void );
	void				calc_num( std::string::iterator it );
public:
	RPN( void );
	RPN( std::string str );
	~RPN( void );
	RPN( const RPN& copy );
	RPN& operator=( const RPN& copy );
	void	init_args( void );

class InvalidArgs: public std::exception
{
	virtual const char* what( void ) const throw() {return ("Error: Invalid Args");};
};

};

#endif