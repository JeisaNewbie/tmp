/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:56:01 by jhwang2           #+#    #+#             */
/*   Updated: 2023/08/26 14:00:51 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <iterator>
#include <sys/time.h>
#include <climits>
#include <algorithm>

class PmergeMe
{
private:
	std::vector<long> vec;
	std::vector<long> vec_after;
	std::deque<long> deque;
	std::deque<long> deque_after;
	std::set<int>	distinct;
	struct timeval	vec_start;
	struct timeval	vec_end;
	struct timeval	deque_start;
	struct timeval	deque_end;
	int	num;
public:
	PmergeMe();
	PmergeMe( int argc );
	~PmergeMe();
	int	check_isnum( char ** argv );
	int	check_duplicate( int argc );
	void init_num( int i, int num );
	int is_num(std::string num);
	void get_num(int argc);
	void get_vecnum(int argc);
	void get_dequenum(int argc);
	void check_sorted();
	void make_pair(std::vector<std::pair<long, long> >	tmp);
	void make_pair(std::deque<std::pair<long, long> >	tmp);
	void binary_search(std::vector<std::pair<long, long> > *tmp, int low, int high, std::pair<long, long> value);
	void binary_search(std::deque<std::pair<long, long> > *tmp, int low, int high, std::pair<long, long> value);
	void binary_search_vec(int low, int high, std::pair<long, long> value);
	void binary_search_deque(int low, int high, std::pair<long, long> value);
	void bs_jacobsthal(std::vector<std::pair<long, long> > tmp);
	void bs_jacobsthal(std::deque<std::pair<long, long> > tmp);
	struct timeval get_td();
	size_t get_sortingtime(int flag);
};

#endif