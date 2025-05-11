/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:21:15 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/11 18:23:33 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

/** the constructor for the PhoneBook class
 * another way for constractor, using an initializer list to initialize its member variables.
 * PhoneBook::PhoneBook() : totalContacts(0), lastIndex(0) {}
 */

PhoneBook::PhoneBook() 
{
	totalContacts = 0;
	lastIndex = 0;
}

/**
 * Iincrements the index circularly.
 * If lastIndex is 7, (7 + 1) % 8 = 0, it wraps around to the beginning.
 * Ensures only 8 contacts are stored — if a 9th contact is added, it overwrites the last one.
 * Keeps track of how many contacts are currently stored. After 8 contacts, this will always stay at 8.	
 */
void PhoneBook::addContact()
{
	contacts[lastIndex].setContact();

	lastIndex = (lastIndex + 1) % 8;
	if(totalContacts < 8)
		totalContacts++;
}

/**
 * This reads the entire input line from the user.
 */
void PhoneBook::searchContacts() const
{
	std::cout << "Index | First Name | Last Name | Nickname" << std::endl;
	for(int i = 0; i < totalContacts; i++)
		contacts->displayBrief(i);
	std::cout << "Enter index to get datail information" << std::endl;
	std::string input;
	int index = 0;
	std::getline(std::cin, input);
	
	try
	{
		index = std::stoi(input);
		if (index < 0 || index >= totalContacts)
		{
			std::cout << "Wrong input." << std::endl;
			return;
		}
		contacts[index].displayFull();
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << "Wrong input, only numbers are allowed" << std::endl;
	}	
	catch(const std::out_of_range& e)
	{
		std::cout << "Wrong input, number is out of range." << '\n';
	}
}
