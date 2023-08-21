#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    int limit = (MAX_VAL < 10) ? MAX_VAL : 10;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "first ten (or less) of numbers:" << std::endl;
        for (int i = 0; i < limit; ++i)
            std::cout << numbers[i] <<std::endl;
        std::cout << "first ten (or less) of tmp:" << std::endl;
        for (int i = 0; i < limit; ++i)
            std::cout << tmp[i] <<std::endl;
        std::cout << "first ten (or less) of test:" << std::endl;
        for (int i = 0; i < limit; ++i)
            std::cout << test[i] <<std::endl;
        std::cout << "first ten (or less) of mirror:" << std::endl;
        for (int i = 0; i < limit; ++i)
            std::cout << mirror[i] <<std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        std::cout << "Trying to fix -2 as a index" << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Trying to fix max value" << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	std::cout << "first ten (or less) of numbers after rand:" << std::endl;
	for (int i = 0; i < limit; ++i)
	    std::cout << numbers[i] <<std::endl;
	std::cout << "first ten (or less) of mirror after rand:" << std::endl;
	for (int i = 0; i < limit; ++i)
	    std::cout << mirror[i] <<std::endl;
    delete [] mirror;//
    return 0;
}