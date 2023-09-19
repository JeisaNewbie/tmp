/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:11:02 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/02 14:01:15 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
 #define SERIALIZER_HPP

#include <cstdint>
#include <iostream>
#include "Data.hpp"

class Serializer
{
public:
	Serializer( void );
	Serializer( const Serializer& copy );
	Serializer& operator=( const Serializer& copy );
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	~Serializer();
};

#endif