/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:51:36 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/07 21:59:30 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();

		Intern &operator=(Intern const &rhs);
		AForm	*makeForm(std::string, std::string);
};
#endif /* ********************************************************** INTERN_H */