/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:16:16 by gamoreno          #+#    #+#             */
/*   Updated: 2023/05/31 19:28:40 by gamoreno         ###   ########.fr       */
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

	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickName() const;
	std::string	getPhoneNumber() const;
	std::string	getSecret() const;
	int	getIndex() const;
	
	void	setFirstName(std::string str);
	void	setLastName(std::string str);
	void	setNickName(std::string str);
	bool	setPhoneNumber(std::string str);
	void	setSecret(std::string str);
	void	setIndex(int n);
	
private:

	int			_index;
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _secret; 
};

#endif