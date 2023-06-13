/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:45:24 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/06 21:16:49 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(void)
{
    Zombie  *zombie;

    zombie = newZombie("zombie1");
    zombie->announce();
    delete zombie;
    randomChump("zombie2");
    return (0);
}