/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:45:49 by jhwang2           #+#    #+#             */
/*   Updated: 2023/10/20 19:45:56 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout<<"Error: No Args"<<std::endl;
		return (1);
	}

	PmergeMe	sort(argc - 1);

	if (sort.check_isnum(&argv[1]))
	{
		std::cout<<"Error: Invalid Num"<<std::endl;
		return (1);
	}

	if (sort.check_duplicate(argc - 1))
	{
		std::cout<<"Error: Duplicate Num"<<std::endl;
		return (1);
	}

	if (argc == 2)
	{
		std::cout<<"Error: One Num"<<std::endl;
		return (1);
	}

	std::cout<<"------------------------------------------------------------------------"<<std::endl;
	std::cout<<"start sorting"<<std::endl;
	std::vector<std::pair<long, long> >	tmp_vec;
	std::deque<std::pair<long, long> > tmp_deque;
	std::cout<<"------------------------------------------------------------------------"<<std::endl;
	sort.get_num(argc - 1);
	std::cout<<"------------------------------------------------------------------------"<<std::endl;
	sort.make_pair(tmp_vec);
	sort.make_pair(tmp_deque);
	sort.get_vecnum(argc - 1);
	sort.get_dequenum(argc - 1);
	std::cout<<"------------------------------------------------------------------------"<<std::endl;
	std::cout<<"Time to process a range of "<<argc - 1<<" elements with std::vector: "<<sort.get_sortingtime(1)<<std::endl<<std::endl;
	std::cout<<"Time to process a range of "<<argc - 1<<" elements with std::deque:  "<<sort.get_sortingtime(0)<<std::endl<<std::endl;
	std::cout<<"------------------------------------------------------------------------"<<std::endl;
	sort.check_sorted();
	std::cout<<"------------------------------------------------------------------------"<<std::endl;
	return (0);
}