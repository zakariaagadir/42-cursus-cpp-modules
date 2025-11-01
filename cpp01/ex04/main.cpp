/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmounji <zmounji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 03:04:37 by zmounji           #+#    #+#             */
/*   Updated: 2025/09/05 22:52:22 by zmounji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	if(argc != 4)
		return(1);

	std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

	if (s1.empty())
	{
		std:: cout << "S1 is empty" << std::endl;
		return (1);
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::string outputFilename = filename + ".replace";
	
	std::ofstream outputFile(outputFilename.c_str());

	if(!outputFile.is_open())
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::string line;
	std::string line2;
	int i = 0;
	while (std::getline(inputFile, line))
	{
		if (line.length() == 0)
			i = 1;
		size_t found_pos ;
		
		while ((found_pos = line.find(s1)) != std::string::npos)
		{
			line.erase(found_pos, s1.length());
			line.insert(found_pos, s2);
			
		}
		std::cout << line ;
		outputFile << line ;
		if (inputFile.good())
		{
			
			outputFile << std::endl;
			std::cout << std::endl;
		}
		
	}

	inputFile.close();
	remove(filename.c_str());
	outputFile.close();
	rename(outputFilename.c_str(),filename.c_str());

    return (0);
}
