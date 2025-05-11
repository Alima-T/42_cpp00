/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:12:02 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/11 19:24:53 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

bool safeGetline(std::string& input) {
	if (!std::getline(std::cin, input)) {
		std::cout << "\nInput interrupted. Exiting.\n";
		return false;
	}
	return true;
}

bool promptAndRead(const std::string& prompt, std::string& field) {
	while (true) {
		std::cout << prompt;
		if (!safeGetline(field)) return false;
		if (!field.empty()) return true;
		std::cout << "This field cannot be empty.\n";
	}
}

bool promptAndReadDigits(const std::string& prompt, std::string& field) {
	while (true) {
		std::cout << prompt;
		if (!safeGetline(field)) return false;
		if (!field.empty() && field.find_first_not_of("0123456789") == std::string::npos)
			return true;
		std::cout << "Phone number must be digits only and not empty.\n";
	}
}

void Contact::setContact()
{
	if (!promptAndRead("First name: ", firstName)) return;
	if (!promptAndRead("Last name: ", lastName)) return;
	if (!promptAndRead("Nickname: ", nickName)) return;
	if (!promptAndReadDigits("Phone number: ", phoneNumber)) return;
	if (!promptAndRead("Darkest secret: ", darkestSecret)) return;
}

/** 
 * 1sets the width parameter of the stream out or in to exactly n
 */
void Contact::displayBrief(int i) const
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
