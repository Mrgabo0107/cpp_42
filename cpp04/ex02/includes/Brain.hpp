/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 05:47:38 by gamoreno          #+#    #+#             */
/*   Updated: 2023/07/06 07:53:11 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{

	public:

		Brain();
		Brain(const Brain &src);
		~Brain();

		Brain&	operator=(const Brain &rhs);

		std::string*	getIdeas(void);
		void			setIdeas(std::string idea);
		
	private:
	
		std::string _ideas[100];
};

#endif /* *********************************************************** BRAIN_H */