/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:12:02 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/08 22:16:36 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip> //to manage input and output formatting
#include "Contact.hpp"

bool safeGetline(std::string& input) {
	if (!std::getline(std::cin, input)) {
		std::cout << "\nInput interrupted. Exiting.\n";
		return false;
	}
	return true;
}

void Contact::setContact()
{
	std::cout << "First name: ";
	if (!safeGetline(firstName)) return;
	std::cout << "Last name: ";
	if (!safeGetline(lastName)) return;
	std::cout << "Nickname: ";
	if (!safeGetline(nickName)) return;
	std::cout << "Phone number: ";
	if (!safeGetline(phoneNumber)) return;
	std::cout << "Darkest secret: ";
	if (!safeGetline(darkestSecret)) return;
	
}

void Contact::displayBrief(int i) const//sets the width parameter of the stream out or in to exactly n
{
	std::cout << std::setw(10) << i << "|";
	std::string fields[3] = {firstName, lastName, nickName};
	for(int i = 0; i < 3; i++)
	{
		std::string val = fields[i];
		if(val.length() > 10)
			val = val.substr(0, 9) + ".";
		std::cout << std::setw(10) << val << "|";
	}
	std::cout <<std::endl;
}

void Contact::displayFull() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName<< std::endl;
	std::cout << "Nick name: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;	
}

bool Contact::isEmpty() const
{
	return firstName.empty();
}