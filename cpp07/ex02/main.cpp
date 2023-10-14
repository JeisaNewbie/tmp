/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:13:31 by jhwang2           #+#    #+#             */
/*   Updated: 2023/10/14 19:53:59 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Array.hpp"

#define	MAX_VAL	10

int	main()
{
	Array<int>	origin(MAX_VAL);
	int *test = new int [MAX_VAL];
	int			num = 0;

	for (int i = 0; i < MAX_VAL; i++)
	{
		num = rand();
		origin[i] = num;
		test[i] = num;
	}

	// try
	// {
	// 	for (int i = 0; i < MAX_VAL + 1; i++)
	// 	{
	// 		std::cout<<"Array<int>: "<<origin[i]<<std::endl;
	// 		std::cout<<"int       : "<<test[i]<<std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	Array<int>	test_arr = origin;
	Array<int>	tmp(origin);

	try
	{
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout<<"Array<int> origin: "<<origin[i]<<std::endl;
			std::cout<<"Array<int> tmp   : "<<tmp[i]<<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	// try
	// {
	// 	origin[-1] = -1;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// try
	// {
	// 	std::cout<<"Array<int> origin: "<<origin[-1]<<std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	delete []test;
	return 0;
}