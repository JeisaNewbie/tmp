/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhwang2 <jhwang2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:09:24 by ahkiler           #+#    #+#             */
/*   Updated: 2023/09/19 21:15:23 by jhwang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
 #define ITER_HPP

template <class T1, class T2>
void iter(T1 address, size_t length, T2 f)
{

	for (size_t i = 0; i < length; i++)
		f(address[i]);
}

#endif