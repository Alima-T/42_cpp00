/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <alima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:22:36 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/07 14:52:21 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact contacts[8];
	int totalContacts;
	int lastIndex;
	
	public:
	PhoneBook();
	void addContact();
	void searchContacts() const;
};

#endif