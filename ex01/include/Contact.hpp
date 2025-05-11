/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <alima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:27:56 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/07 14:05:01 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
	std::string firstName;
	std:: string lastName; 
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	public:
	void setContact();
	void displayBrief(int index) const;
	void displayFull() const;
	bool isEmpty() const;
};

#endif
