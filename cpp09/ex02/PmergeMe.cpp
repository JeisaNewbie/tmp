/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 04:49:43 by jhwang2           #+#    #+#             */
/*   Updated: 2023/10/20 19:44:11 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( int argc ): vec(argc), vec_after(argc), deque(argc), deque_after(argc), num(argc)
{
	this->vec.clear();
	this->vec_after.clear();
	this->deque.clear();
	this->deque_after.clear();
}

PmergeMe::~PmergeMe()
{
}

int	PmergeMe::is_num(std::string num)
{
	std::string::iterator it = num.begin();
	std::string::iterator ite = num.end();

	for (; it != ite; it++)
	{
		if (!std::isdigit(*it))
			return (1);
	}
	return (0);

}

int	PmergeMe::check_isnum( char **argv )
{
	std::string	num_str;
	std::stringstream ss;
	long	num;

	for (int i = 0; argv[i] != NULL; i++)
	{
		num_str = argv[i];
		if (is_num(num_str))
			return (1);
		ss << num_str;
		ss >> num;
		if (num < 0 || num > 2147483647)
			return (1);
		init_num(i, num);
		ss.clear();
	}
	return (0);
}

void	PmergeMe::init_num( int i, int num )
{
	this->distinct.insert(num);
	this->vec[i] = num;
	this->deque[i] = num;
}

int	PmergeMe::check_duplicate( int argc )
{
	if (this->distinct.size() != argc)
		return (1);
	return (0);
}

void	PmergeMe::binary_search(std::vector<std::pair<long, long> > *tmp, int low, int high, std::pair<long, long> value)
{
	int	mid = 0;

	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (value.first < (tmp->begin() + mid)->first)
			high = mid;
		else
			low = mid + 1;
	}
	tmp->insert(tmp->begin() + low, value);
	this->vec_after.insert(this->vec_after.begin() + low, value.first);
}

void	PmergeMe::binary_search(std::deque<std::pair<long, long> > *tmp, int low, int high, std::pair<long, long> value)
{
	int	mid = 0;

	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (value.first < (tmp->begin() + mid)->first)
			high = mid;
		else
			low = mid + 1;
	}
	tmp->insert(tmp->begin() + low, value);
	this->deque_after.insert(this->deque_after.begin() + low, value.first);
}

void	PmergeMe::binary_search_vec(int low, int high, std::pair<long, long> value)
{
	int	mid = 0;

	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (value.second < this->vec_after[mid])
			high = mid;
		else
			low = mid + 1;
	}
	this->vec_after.insert(this->vec_after.begin() + low, value.second);
}

void	PmergeMe::binary_search_deque(int low, int high, std::pair<long, long> value)
{
	int	mid = 0;

	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (value.second < this->deque_after[mid])
			high = mid;
		else
			low = mid + 1;
	}
	this->deque_after.insert(this->deque_after.begin() + low, value.second);
}

void	PmergeMe::make_pair(std::vector<std::pair<long, long> >	tmp)
{
	this->vec_start = get_td();
	std::pair<long, long>	ab;
	int j = 0;

	for (int i = 0; i < this->num; i += 2)
	{
		if (i + 1 == this->num)
		{
			ab = std::make_pair(LONG_MAX, this->vec[i]);
			binary_search(&tmp, 0, j, ab);
			break;
		}
		ab = std::make_pair(this->vec[i], this->vec[i + 1]);
		if (ab.first < ab.second)
			std::swap(ab.first, ab.second);
		binary_search(&tmp, 0, j, ab);
		j++;
	}
	bs_jacobsthal(tmp);
}

void	PmergeMe::make_pair(std::deque<std::pair<long, long> >	tmp)
{
	this->deque_start = get_td();
	std::pair<long, long>	ab;
	int j = 0;

	for (int i = 0; i < this->num; i += 2)
	{
		if (i + 1 == this->num)
		{
			ab = std::make_pair(LONG_MAX, this->deque[i]);
			binary_search(&tmp, 0, j, ab);
			break;
		}
		ab = std::make_pair(this->deque[i], this->deque[i + 1]);
		if (ab.first < ab.second)
			std::swap(ab.first, ab.second);
		binary_search(&tmp, 0, j, ab);
		j++;
	}
	bs_jacobsthal(tmp);
}

int	jacobsthal_num(int i)
{
	if (i <= 0)
		return (0);
	else if (i == 1)
		return (1);
	else
		return (jacobsthal_num(i - 1) + 2 * jacobsthal_num(i - 2));
}

void	PmergeMe::bs_jacobsthal(std::vector<std::pair<long, long> > tmp)
{
	int max_before = 0;
	int max_after = 0;
	int	high = 0;
	int	end = 0;
	int i = 2;

	while (1)
	{
		if (max_after == (this->num / 2 + this->num % 2))
			break ;
		max_before = max_after;
		max_after = jacobsthal_num(i++);
		if (max_after > (this->num / 2 + this->num % 2))
			max_after = (this->num / 2 + this->num % 2);
		high = max_before + max_after;
		for (int max = max_after; max > max_before; max--)
		{
			binary_search_vec(0, high - end++, tmp[max - 1]);
			if (tmp[max - 2].first > tmp[max - 1].second)
				high++;
		}
		end = 1;
	}
	this->vec_end = get_td();
}

void	PmergeMe::bs_jacobsthal(std::deque<std::pair<long, long> > tmp)
{
	int max_before = 0;
	int max_after = 0;
	int	high = 0;
	int	end = 0;
	int i = 2;

	while (1)
	{
		if (max_after == (this->num / 2 + this->num % 2))
			break ;
		max_before = max_after;
		max_after = jacobsthal_num(i++);
		if (max_after > (this->num / 2 + this->num % 2))
			max_after = (this->num / 2 + this->num % 2);
		high = max_before + max_after;
		for (int max = max_after; max > max_before; max--)
		{
			binary_search_deque(0, high - end++, tmp[max - 1]);
			if (max > 1 && tmp[max - 2].first > tmp[max - 1].second)
				high++;
		}
		end = 1;
	}
	this->deque_end = get_td();
}

void PmergeMe::get_num(int argc)
{
	std::cout<<"Vec_num:   ";
	for (int i = 0; i < argc; i++)
		std::cout<<vec[i]<<" ";
	std::cout<<std::endl<<std::endl;
	std::cout<<"Deque_num: ";
	for (int i = 0; i < argc; i++)
		std::cout<<deque[i]<<" ";
	std::cout<<std::endl;
}

void PmergeMe::get_vecnum(int argc)
{
	std::cout<<"\nVec_num:   ";
	for (int i = 0; i < argc; i++)
		std::cout<<this->vec_after[i]<<" ";
	std::cout<<std::endl<<std::endl;
}

void PmergeMe::get_dequenum(int argc)
{
	std::cout<<"Deque_num: ";
	for (int i = 0; i < argc; i++)
		std::cout<<this->deque_after[i]<<" ";
	std::cout<<std::endl<<std::endl;
}

void PmergeMe::check_sorted()
{
	std::cout<<"sorted: "<<std::is_sorted(this->vec_after.begin(), this->vec_after.end())<<std::endl;
	std::cout<<"sorted: "<<std::is_sorted(this->deque_after.begin(), this->deque_after.end())<<std::endl;
}

struct timeval	PmergeMe::get_td()
{
	struct timeval	tv;

	if (gettimeofday (&tv, NULL))
		throw ;
	return (tv);
}

size_t	PmergeMe::get_sortingtime(int flag)
{
	if (flag)
		return ((vec_end.tv_sec - vec_start.tv_sec - 1) * (size_t)1000000 + (vec_end.tv_usec + 1000000 - vec_start.tv_usec));
	return ((deque_end.tv_sec - deque_start.tv_sec - 1) * (size_t)1000000 + (deque_end.tv_usec + 1000000 - deque_start.tv_usec));
}