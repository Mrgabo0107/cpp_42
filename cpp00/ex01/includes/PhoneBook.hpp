/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:45:08 by gamoreno          #+#    #+#             */
/*   Updated: 2023/05/31 21:32:31 by gamoreno         ###   ########.fr       */
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
	int		getOldestIndex(void) const;

	void	setContact(Contact contact, int indexToFill);

	void	usageMessage(void) const;

private:

	Contact	_contacts[8];
	int		_indexToFill;
};

#endif