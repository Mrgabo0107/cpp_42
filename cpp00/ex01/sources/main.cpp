/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:16:54 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/02 03:05:49 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <iomanip>

void	OptionAddFirstName(Contact *contact)
{
	std::string currStr;
	
	while (1)
	{
		currStr = "";
		std::cout << "type the firstname: ";
		std::getline(std::cin, currStr);
		if (contact->setFirstName(currStr) == true)
			break;
	}
}

void	OptionAddLastName(Contact *contact)
{
	std::string currStr;

	while (1)
	{
		currStr = "";
		std::cout << "type the lastname: ";
		std::getline(std::cin, currStr);
		if (contact->setLastName(currStr) == true)
			break;
	}
}

void	OptionAddNickName(Contact *contact)
{
	std::string currStr;

	while (1)
	{
		currStr = "";
		std::cout << "type some nickname: ";
		std::getline(std::cin, currStr);
		if (contact->setNickName(currStr) == true)
			break;
	}
}
void	OptionAddPhoneNumber(Contact *contact)
{
	std::string currStr;

	while (1)
	{
		currStr = "";
		std::cout << "type the phone number: ";
		std::getline(std::cin, currStr);
		if (contact->setPhoneNumber(currStr) == true)
			break;
	}
}

void	OptionAddSecret(Contact *contact)
{
	std::string currStr;

	while (1)
	{
		currStr = "";
		std::cout << "type the dark secret: ";
		std::getline(std::cin, currStr);
		if (contact->setSecret(currStr) == true)
			break;
	}
}

void	OptionAdd(Phonebook *phoneBook)
{
	Contact     contact;
    std::string currStr;

	std::cout << std::endl;
	std::cout << "Please complete the contact data:" << std::endl \
	<< std::endl;
	OptionAddFirstName(&contact);
	OptionAddLastName(&contact);
	OptionAddNickName(&contact);
	OptionAddPhoneNumber(&contact);
	OptionAddSecret(&contact);
	contact.setIndex(phoneBook->getIndexToFill());
	phoneBook->setContact(&contact);
	std::cout << std::endl;
	std::cout << "The contact has been added to the phonebook." \
	<< std::endl << std::endl;
	return;
}

void	beginOfTable(void)
{
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first name";
	std::cout << "|" << std::setw(10) << "last name";
	std::cout << "|" << std::setw(10) << "nickname" << "|" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	return;
}

std::string truncate(std::string str)
{
	if (str.size() >= 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	displayAvalaibleContacts(Phonebook *phonebook)
{
	int	numberOfContacts = phonebook->getNumberOfsetContacts();
	int	i = 0;

	if (numberOfContacts <= 0)
	{
		std::cout << std::endl \
		<< "Add a contact after searching for it" << std::endl;
		return;
	}
	beginOfTable();
	while (i < numberOfContacts)
	{
		Contact contact;
		contact = phonebook->getContact(i);
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << truncate(contact.getFirstName());
		std::cout << "|" << std::setw(10) << truncate(contact.getLastName());
		std::cout << "|" << std::setw(10) << truncate(contact.getNickName()) \
		<< "|" << std::endl;
		i++;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	return;
}

bool	isGoodIndex(std::string str, Phonebook *phoneBook)
{
	if (str.length() != 1 || \
	static_cast<int>(str[0]) - 48 < 1 || \
	static_cast<int>(str[0]) - 48 > phoneBook->getNumberOfsetContacts())
	{
		std::cout << "Type a number between 1 and " << \
		phoneBook->getNumberOfsetContacts() << std::endl;
		return false;
	}
	return true;
}

void showContactInfo(Phonebook *phoneBook, int index)
{
	Contact currContact;

	currContact = phoneBook->getContact(index);
	std::cout << "the contact number " << index + 1 \
	<< " has the following information:" << std::endl << std::endl;
	std::cout << "First name: " << currContact.getFirstName() << std::endl;
	std::cout << "Last name: " << currContact.getLastName() << std::endl;
	std::cout << "Nickname: " << currContact.getNickName() << std::endl;
	std::cout << "Phone number: " << currContact.getPhoneNumber() << std::endl;
	std::cout << "Dark secret: " << currContact.getSecret() << std::endl;
	return;
}

int	selectContactMessage(Phonebook *phoneBook)
{
	std::string	currInput;

	while(1)
	{
		currInput = "";
		std::cout << std::endl << "to see all contact information type its index: ";
		std::getline(std::cin, currInput);
		if (isGoodIndex(currInput, phoneBook) == true)
			return (static_cast<int>(currInput[0] - 48));
	}
	// return 0;
}
void	OptionSearch(Phonebook *phoneBook)
{
	displayAvalaibleContacts(phoneBook);
	showContactInfo(phoneBook, selectContactMessage(phoneBook) - 1);
	return;
}

int main(void)
{
    Phonebook       phoneBook;
    std::string		currComand;

    while (1)
    {
		currComand = "";
        phoneBook.usageMessage();
        std::getline(std::cin, currComand);
        if (!currComand.compare("SEARCH"))
            OptionSearch(&phoneBook);
        else if (!currComand.compare("ADD"))
            OptionAdd(&phoneBook);
        else if (!currComand.compare("EXIT"))
            break;
    }
    return (0);
}
