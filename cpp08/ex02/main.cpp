/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:45:49 by jhwang2           #+#    #+#             */
/*   Updated: 2023/10/17 19:50:13 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout<<"---------------mstack--------------\n";
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout<<"---------------stack--------------\n";
	std::stack<int> s(mstack);
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout<<"---------------list--------------\n";
	std::list<int>	list_tmp;

	list_tmp.push_back(5);
	list_tmp.push_back(17);
	std::cout << list_tmp.back() << std::endl;
	list_tmp.pop_back();
	std::cout << list_tmp.size() << std::endl;
	list_tmp.push_back(3);
	list_tmp.push_back(5);
	list_tmp.push_back(737);
	//[...]
	list_tmp.push_back(0);
	std::list<int>::iterator	it_list = list_tmp.begin();
	std::list<int>::iterator	ite_list = list_tmp.end();
	++it_list;
	--it_list;
	while (it_list != ite_list)
	{
	std::cout << *it_list << std::endl;
	++it_list;
	}

	std::cout<<"-------------------------------------\n";
	MutantStack<int> tmpstack;
	MutantStack<int> zerostack;
	tmpstack = mstack;
	mstack = zerostack;
	MutantStack<int>::iterator it_tmp = tmpstack.begin();
	MutantStack<int>::iterator ite_tmp = tmpstack.end();
	++it_tmp;
	--it_tmp;
	while (it_tmp != ite_tmp)
	{
	std::cout << *it_tmp << std::endl;
	++it_tmp;
	}
	std::cout<<"---------------mstack--------------\n";
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	return 0;
}