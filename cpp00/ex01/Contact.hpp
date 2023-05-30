/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:16:16 by gamoreno          #+#    #+#             */
/*   Updated: 2023/05/30 21:28:49 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>

class Contact
{
public:
	Contact(void);
	~Contact(void);
	void	init(void);
	void	see(int	index) const;
	void	seeAll(int index) const;
	void	setIndex(int i);

private:
	int			_index;
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret. 

	std::string	_getInput(std::string str) const;
};

#endif