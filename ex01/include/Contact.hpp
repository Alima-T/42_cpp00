/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:06:54 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/11 18:07:00 by aokhapki         ###   ########.fr       */
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
