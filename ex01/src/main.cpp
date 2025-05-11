/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:12:28 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/08 22:19:06 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {
	PhoneBook phonebook;
	std::string command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)) //This reads the entire input line from the user into the command string.
		{
			std::cout << "\nEOF detected (Ctrl+D). Exiting...\n";
			break;
		}

		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (command == "EXIT")
			break;
		else if (!command.empty())
			std::cout << "Unknown command: " << command << std::endl;
	}
	return 0;
}
