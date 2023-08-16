/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:30:56 by gamoreno          #+#    #+#             */
/*   Updated: 2023/08/16 21:49:30 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T& a, const T& b){
    return (a < b) ? a : b;
}

template <typename T>
T max(const T& a, const T& b){
    return (a > b) ? a : b;
}
 
// For test non comparable classes
// class NoComparison{
//     private:
//         int value;
//     public:
//         NoComparison(int v) : value(v) {(void)value;}
// };
#endif