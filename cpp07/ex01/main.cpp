/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:30:27 by ahkiler           #+#    #+#             */
/*   Updated: 2023/10/17 14:22:21 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void to_int (const char& num)
{
	int i = static_cast<int>(num);
	std::cout<<i<<std::endl;
}

void  to_char(const int& num)
{
	char c = num + 40;
	std::cout<<c<<std::endl;
}

void add(const int& num)
{
	std::cout<<num + 1<<std::endl;
}

void print_s(const std::string& str)
{
	std::cout<<str<<std::endl;
}

int main()
{
	size_t length = 10;
	int arr_i[10] = {0,1,2,3,4,5,6,7,8,9};
	char arr_c[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	std::string arr_s[5] = {"hello", "world", "this", "is", "jhwang2"};
	std::cout<<"---------\n";
	std::cout<<"add\n";
	iter<int>(arr_i, length, add);
	std::cout<<"---------\n";
	std::cout<<"to_char\n";
	iter<int>(arr_i, length, to_char);
	std::cout<<"---------\n";
	std::cout<<"to_int\n";
	iter<char>(arr_c, length, to_int);
	std::cout<<"---------\n";
	std::cout<<"print_s\n";
	iter<std::string>(arr_s, 5, print_s);
}