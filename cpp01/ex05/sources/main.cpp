/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:31:42 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/12 17:46:13 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int ac, char **ag)
{
	Harl	harl;

	if (ac == 2)
		harl.complain(ag[1]);
	else
		harl.usageMessage();
	return 0;
}