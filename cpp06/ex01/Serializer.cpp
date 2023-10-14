/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:54:49 by ahkiler           #+#    #+#             */
/*   Updated: 2023/10/12 15:52:27 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void )
{
	// std::cout<<"Serializer Default Constructor called"<<std::endl;
}

Serializer::Serializer( const Serializer& copy )
{
	// std::cout<<"Serializer Default Copy Constructor called"<<std::endl;
	(void)copy;
}

Serializer& Serializer::operator=( const Serializer& copy )
{
	(void)copy;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

Serializer::~Serializer()
{
	// std::cout<<"Serializer Default Destructor called"<<std::endl;
}