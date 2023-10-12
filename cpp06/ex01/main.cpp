/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:30:55 by ahkiler           #+#    #+#             */
/*   Updated: 2023/10/12 15:51:49 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data t;
	t.tmp_int = 10;
	std::cout<<"T_Address: "<<&t<<std::endl;
	std::cout<<"T_int: "<<t.tmp_int<<std::endl;
	std::cout<<"ST_Address: "<<Serializer::serialize(&t)<<std::endl;
	std::cout<<"DST_Address: "<<Serializer::deserialize(Serializer::serialize(&t))<<std::endl;
	std::cout<<"T_int: "<<t.tmp_int<<std::endl;
}