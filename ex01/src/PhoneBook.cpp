/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:21:15 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/11 19:23:44 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "PhoneBook.hpp"
// #include <iostream>
// #include <limits>

// /** the constructor for the PhoneBook class
//  * another way for constractor, using an initializer list to initialize its member variables.
//  * PhoneBook::PhoneBook() : totalContacts(0), lastIndex(0) {}
//  */

// PhoneBook::PhoneBook() 
// {
// 	totalContacts = 0;
// 	lastIndex = 0;
// }

// /**
//  * Iincrements the index circularly.
//  * If lastIndex is 7, (7 + 1) % 8 = 0, it wraps around to the beginning.
//  * Ensures only 8 contacts are stored — if a 9th contact is added, it overwrites the last one.
//  * Keeps track of how many contacts are currently stored. After 8 contacts, this will always stay at 8.	
//  */
// void PhoneBook::addContact()
// {
// 	contacts[lastIndex].setContact();

// 	lastIndex = (lastIndex + 1) % 8;
// 	if(totalContacts < 8)
// 		totalContacts++;
// }

// /**
//  * This reads the entire input line from the user.
//  */
// void PhoneBook::searchContacts() const
// {
// 	std::cout << "Index | First Name | Last Name | Nickname" << std::endl;
// 	for(int i = 0; i < totalContacts; i++)
// 		contacts[i].displayBrief(i);
// 	std::cout << "Enter index to get datail information" << std::endl;
// 	std::string input;
// 	int index = 0;
// 	std::getline(std::cin, input);
	
// 	try
// 	{
// 		index = std::stoi(input);
// 		if (index < 0 || index >= totalContacts)
// 		{
// 			std::cout << "Wrong input." << std::endl;
// 			return;
// 		}
// 		contacts[index].displayFull();
// 	}
// 	catch(const std::invalid_argument& e)
// 	{
// 		std::cout << "Wrong input, only numbers are allowed" << std::endl;
// 	}	
// 	catch(const std::out_of_range& e)
// 	{
// 		std::cout << "Wrong input, number is out of range." << '\n';
// 	}
// }

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

/** the constructor for the PhoneBook class
 * another way for constractor, using an initializer list to initialize its member variables.
 * PhoneBook::PhoneBook() : totalContacts(0), lastIndex(0), oldestIndex(0) {}
 */

PhoneBook::PhoneBook() 
{
	totalContacts = 0;
	lastIndex = 0;
	oldestIndex = 0; // Track which index has the oldest contact
}

/**
 * Implements a circular buffer to manage contacts:
 * - lastIndex points to the position where the next contact will be added
 * - oldestIndex tracks which position has the oldest contact
 * - totalContacts tracks how many unique contacts have been added (max 8)
 * - If we already have 8 contacts, we overwrite the oldest contact (FIFO order)
 */
void PhoneBook::addContact()
{
	contacts[lastIndex].setContact();

	lastIndex = (lastIndex + 1) % 8;
	if(totalContacts < 8)
		totalContacts++;
	else
		oldestIndex = (oldestIndex + 1) % 8; // Update oldest index when overwriting
}

/**
 * This reads the entire input line from the user.
 * Displays contacts in their logical order (oldest to newest),
 * not necessarily in their physical array order.
 */
void PhoneBook::searchContacts() const
{
	std::cout << "Index | First Name | Last Name | Nickname" << std::endl;
	
	// Display contacts in order from oldest to newest
	for(int i = 0; i < totalContacts; i++) {
		// Calculate the actual array index for this logical position
		int actualIndex = (oldestIndex + i) % 8;
		contacts[actualIndex].displayBrief(i);
	}
	
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
		
		// Convert logical index to physical array index
		int actualIndex = (oldestIndex + index) % 8;
		contacts[actualIndex].displayFull();
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