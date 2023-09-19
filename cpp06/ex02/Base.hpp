/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:37:25 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/02 16:49:27 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
 #define BASE_HPP

#include <iostream>

class Base
{
public:
	virtual ~Base( void );
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif