/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:54:49 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/02 13:58:59 by ahkiler          ###   ########.fr       */
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
}

Serializer& Serializer::operator=( const Serializer& copy )
{
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