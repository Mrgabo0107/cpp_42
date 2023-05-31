/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:44:57 by gamoreno          #+#    #+#             */
/*   Updated: 2023/05/31 20:44:58 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact()
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

void Contact::setFirstName(std::string str)
{
	this->_firstName = str;
	return;
}

void Contact::setLastName(std::string str)
{
	this->_lastName = str;
	return;
}

void Contact::setNickName(std::string str)
{
	this->_nickName = str;
	return;
}

bool Contact::setPhoneNumber(std::string number)
{
	std::size_t nonNumeric = number.find_first_not_of("+0123456789 ");
	if (nonNumeric != std::string::npos)
		return false;
	this->_phoneNumber = number;
	return true;
}

void Contact::setSecret(std::string secret)
{
	this->_secret = secret;
	return;
}

void Contact::setIndex(int n)
{
	this->_index = n;
	return;
}