/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:37:37 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/22 22:11:02 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
// #include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
    private:
        typename std::stack<T>::container_type::iterator current;

    public:
        iterator(typename std::stack<T>::container_type::iterator it) : current(it) {}

        bool operator==(const iterator &other) const { return current == other.current; }
        bool operator!=(const iterator &other) const { return !(*this == other); }

        iterator &operator++()
        {
            ++current;
            return *this;
        }

        iterator &operator--()
        {
            --current;
            return *this;
        }

        T &operator*() { return *current; }
    };

    typedef typename std::stack<T>::container_type::iterator container_iterator;

    iterator begin() { return iterator(std::stack<T>::c.begin()); }
    iterator end() { return iterator(std::stack<T>::c.end()); }
};

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    return 0;
}

