/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkiler <ahkiler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:30:55 by ahkiler           #+#    #+#             */
/*   Updated: 2023/06/02 17:07:38 by ahkiler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(int argc, char **argv)
{
	Base *base = generate();
	Base &base_ref = *base;
	identify (base);
	identify (base_ref);

	delete base;
}