/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:51:46 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/02 01:51:59 by gamoreno         ###   ########.fr       */
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

int	Phonebook::getIndexToFill(void) const
{
    return this->_indexToFill;
}

void Phonebook::setContact(Contact *contact)
{
	this->_contacts[_indexToFill] = *contact;
    if (_indexToFill < 7)
        _indexToFill++;
    else
        _indexToFill = 0;
    return;
}

void Phonebook::usageMessage(void) const
{
    std::cout << std::endl;
    std::cout << "--------------Phonebook usage--------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Type \"ADD\" to add new contact" << std::endl;
    std::cout << "Type \"SEARCH\" to select a contact to see" << std::endl;
    std::cout << "Type \"EXIT\" to finish the Phonebook" << std::endl;
    std::cout << std::endl;
    std::cout << "---------Please enter a good command-------" << std::endl;
    std::cout << std::endl;
	return;
}

int Phonebook::getNumberOfsetContacts(void) const
{
    int i = 0;

    while (this->_contacts[i].getIndex() >= 0 && i < 8)
        i++;
    return (i);
}