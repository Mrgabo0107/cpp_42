/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreno <gamoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:51:26 by gamoreno          #+#    #+#             */
/*   Updated: 2023/06/12 02:33:15 by gamoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
// #include <string>

void	usageMessage(void)
{
	std::cout << "TO LAUNCH THIS PROGRAM:" << std::endl;
	std::cout << std::endl;
	std::cout << "Please enter a file name, the string to be replaced" << std::endl;
	std::cout << "and the string to replace the previous." << std::endl;
}

void	replaceStrings(std::string& line, std::string toReplace, std::string newString)
{
	long unsigned int	i = 0;

	while ((i = line.find(toReplace, i)) != std::string::npos)
	{
		line.erase(i, toReplace.length());
		line.insert(i, newString);
		i += newString.length();
	}
}

int main(int ac, char **ag)
{
	std::fstream	infile;
	std::fstream	outfile;

	if (ac == 4)
	{
		std::string	outfileName = ag[1];
		std::string	line;

		outfileName.append(".replace");
		infile.open(ag[1], std::ios::in);
		if (!infile.is_open())
			return(std::cerr << "error oppening infile\n", 1);
		outfile.open(outfileName.c_str(), std::ios::out);
		if (!outfile.is_open())
			return(infile.close(), std::cerr << "error creating outfile\n", 1);
		while (std::getline(infile, line, '\0'))
		{
			replaceStrings(line, ag[2], ag[3]);
			outfile << line;
		}
		outfile.close();
		infile.close();
	}
	else
		usageMessage();
	return (0);
}