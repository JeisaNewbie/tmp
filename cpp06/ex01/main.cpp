/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:30:55 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/02 14:34:33 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(int argc, char **argv)
{
	Data t;
	Serializer s;

	std::cout<<"T_Address: "<<&t<<std::endl;
	std::cout<<"ST_Address: "<<s.serialize(&t)<<std::endl;
	std::cout<<"DST_Address: "<<s.deserialize(s.serialize(&t))<<std::endl;
}