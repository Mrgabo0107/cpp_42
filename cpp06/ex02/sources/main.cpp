/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:11:48 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/16 01:17:45 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate() 
{
	std::srand(time(0));
	int choice = std::rand() % 3;
	switch (choice)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return 0;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A*" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B*" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C*" << std::endl;
	else
		std::cout << "Unknown pointer" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "&A" << std::endl;
		return ;
	}
	catch (std::exception &e){}
	try 
	{
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "&B" << std::endl;
		return ;
	}
	catch (std::exception &e){}
	try 
	{
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "&C" << std::endl;
		return ;
	}
	catch (std::exception &e){}
	std::cout << "Unknown reference" << std::endl;
}

int main()
{
	Base* BasePtrNull = NULL;
	Base& BaseRefNull = *BasePtrNull;
	Base* BasePtr = generate();
	Base& BaseRef = *BasePtr;
	
	identify(BasePtr);
	identify(BaseRef);
	identify(BasePtrNull);
	identify(BaseRefNull);
	
	delete BasePtr;
	
	return 0;
}
