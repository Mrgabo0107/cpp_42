/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:44:57 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/01 23:56:54 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact()
: _index(-1), _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), \
_secret("")
{
	return;
}

Contact::~Contact()
{
	return;
}

std::string Contact::getFirstName(void) const
{
	return this->_firstName;
}

std::string Contact::getLastName(void) const
{
	return this->_lastName;
}

std::string Contact::getNickName(void) const
{
	return this->_nickName;
}

std::string Contact::getPhoneNumber(void) const
{
	return this->_phoneNumber;
}

std::string Contact::getSecret(void) const
{
	return this->_secret;
}

int Contact::getIndex(void) const
{
    return this->_index;
}

bool Contact::setFirstName(std::string str)
{
	if (str.find_first_not_of(" \t") == std::string::npos)
		return (false);
	this->_firstName = str;
	return (true);
}

bool Contact::setLastName(std::string str)
{
	if (str.find_first_not_of(" \t") == std::string::npos)
		return (false);
	this->_lastName = str;
	return (true);
}

bool Contact::setNickName(std::string str)
{
	if (str.find_first_not_of(" \t") == std::string::npos)
		return (false);
	this->_nickName = str;
	return (true);
}

bool Contact::setPhoneNumber(std::string number)
{
	std::string subStr;

	subStr = number;
	if(subStr[0] == '+')
		subStr = subStr.substr(1, subStr.length() - 1);
	std::size_t nonNumeric = subStr.find_first_not_of("0123456789 ");
	if (nonNumeric != std::string::npos \
	|| subStr.find_first_not_of(" \t") == std::string::npos)
		return (false);
	this->_phoneNumber = number;
	return (true);
}

bool Contact::setSecret(std::string str)
{
	if (str.find_first_not_of(" \t") == std::string::npos)
		return (false);
	this->_secret = str;
	return (true);
}

void Contact::setIndex(int n)
{
	this->_index = n;
	return;
}