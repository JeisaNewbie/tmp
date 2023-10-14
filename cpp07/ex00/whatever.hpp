/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:30:55 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/03 11:37:47 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
 #define WHATEVER_HPP

template <typename T>
void swap(T& num1, T& num2)
{
	T tmp = num1;
	num1 = num2;
	num2 = tmp;
}

template <typename T>
T min(T num1, T num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

template <typename T>
T max(T num1, T num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

#endif