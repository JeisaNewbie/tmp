/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:30:27 by ahkiler           #+#    #+#             */
/*   Updated: 2023/10/14 15:14:36 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void to_int (char num)
{
	int i = static_cast<int>(num);
	std::cout<<i<<std::endl;
}

void  to_char(const int num)
{
	char c = num + 40;
	std::cout<<c<<std::endl;
}

int add(const int num)
{
	std::cout<<num + 1<<std::endl;
	return (0);
}

// int add(int num)
// {
// 	std::cout<<num + 1<<std::endl;
// 	return (0);
// }

int main()
{
	int arr_i[10] = {0,1,2,3,4,5,6,7,8,9};
	char arr_c[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	std::cout<<"---------\n";
	std::cout<<"add\n";
	iter(arr_i, 10, add);
	std::cout<<"---------\n";
	std::cout<<"to_char\n";
	iter(arr_i, 10, to_char);
	std::cout<<"---------\n";
	std::cout<<"add\n";
	iter(arr_c, 10, add);
	std::cout<<"---------\n";
	std::cout<<"to_int\n";
	iter(arr_c, 10, to_int);
}