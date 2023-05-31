/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:51:46 by gamoreno          #+#    #+#             */
/*   Updated: 2023/05/31 21:33:16 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

Phonebook::Phonebook(void) : _indexToFill(0)
{
    return;
}

Phonebook::~Phonebook(void)
{
    return;
}

Contact Phonebook::getContact(int index) const
{
    return this->_contacts[index];
}

int	Phonebook::getOldestIndex(void) const
{
    return this->_indexToFill;
}

void Phonebook::setContact(Contact contact, int indexToFill)
{
	this->_contacts[indexToFill] = contact;
	_indexToFill = (_indexToFill < 8) ? _indexToFill++ : _indexToFill = 0;
	return;
}

void Phonebook::usageMessage(void) const
{
	
	return;
}