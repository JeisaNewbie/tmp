/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:09:24 by ahkiler           #+#    #+#             */
/*   Updated: 2023/10/17 13:44:24 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
 #define ITER_HPP

template <class T>
void iter(const T *address, size_t length, void (*f)(T const &))
{

	for (size_t i = 0; i < length; i++)
		f(address[i]);
}

#endif