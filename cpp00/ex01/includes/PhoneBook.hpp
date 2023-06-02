/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:45:08 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/02 01:16:29 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class Phonebook
{
public:

	Phonebook();
	~Phonebook();

	Contact getContact(int index) const;
	int		getIndexToFill(void) const;
	int		getNumberOfsetContacts(void) const;

	void	setContact(Contact *contact);

	void	usageMessage(void) const;

private:

	Contact	_contacts[8];
	int		_indexToFill;
	
};

#endif