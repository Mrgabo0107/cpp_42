/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:11:38 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/16 00:54:59 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

#endif /* ************************************************************ BASE_H */