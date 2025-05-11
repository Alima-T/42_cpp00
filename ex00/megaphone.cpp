/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:43:19 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/11 18:27:45 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for(int i = 1; i < ac; ++i)
	{
		for(int j = 0; av[i][j]; ++j)
			std::cout << static_cast<char>(std::toupper(av[i][j]));
	}
	std::cout<<std::endl;
	return (0);
}
