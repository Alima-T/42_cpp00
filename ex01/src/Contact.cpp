/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:12:02 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/11 22:08:07 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <iomanip>
#include "Contact.hpp"
//<cctype>  for character classification and manipulation 
//<iomanip> for formatting output

bool isStrictAlpha(const std::string &str) {
	if (str.empty()) return false;
	for (size_t i = 0; i < str.length(); i++) {
		if (!isalpha(str[i])) {
			return false;
		}
	}
	return true;
}

bool isStrictDigits(const std::string &str) {
	if (str.empty()) return false;
	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

bool isNoWhitespace(const std::string &str) {
	if (str.empty()) return false;
	for (size_t i = 0; i < str.length(); i++) {
		if (isspace(str[i])) {
			return false;
		}
	}
	return true;
}

bool safeGetline(std::string &input) {
	if (!std::getline(std::cin, input)) {
		std::cout << "\nInput interrupted. Exiting.\n";
		return false;
	}
	return true;
}

bool promptAndReadAlpha(const std::string &prompt, std::string &field) {
	while (true) {
		std::cout << prompt;
		if (!safeGetline(field)) return false;
		if (isStrictAlpha(field)) return true;
		std::cout << "ERROR: Only letters (A-Z/a-z) allowed. No spaces/numbers/symbols.\n";
	}
}

bool promptAndReadDigits(const std::string &prompt, std::string &field) {
	while (true) {
		std::cout << prompt;
		if (!safeGetline(field)) return false;
		if (isStrictDigits(field)) return true;
		std::cout << "ERROR: Only digits allowed. No spaces/symbols.\n";
	}
}

void Contact::setContact() {
	if (!promptAndReadAlpha("First name: ", firstName)) return;
	if (!promptAndReadAlpha("Last name: ", lastName)) return;
	if (!promptAndReadAlpha("Nickname: ", nickName)) return;
	if (!promptAndReadDigits("Phone number: ", phoneNumber)) return;
	if (!promptAndReadAlpha("Darkest secret: ", darkestSecret)) return;
}

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
