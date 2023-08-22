/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:36:21 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/22 05:51:46 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <stdexcept>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		Span& operator=(Span const &rhs);

		void			addNumber(int num);
		void			addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		unsigned int			getMaxCapacity() const;
		int						getNumberAt(size_t index) const;
		const std::vector<int>	&getNumberVector() const;

	private:
		std::vector<int> _numbers;
		unsigned int _maxCapacity;
};

std::ostream &			operator<<(std::ostream &o, Span const &i);

#endif /* ************************************************************ SPAN_H */