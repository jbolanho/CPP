/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CopyAndChange.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:01:22 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 15:01:22 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CopyAndChange.hpp"
#include <fstream>
#include <iostream>

void CopyAndChange(const std::string& inputFile, const std::string& s1, const std::string& s2)
{
    std::ifstream infile(inputFile.c_str());
    if (!infile.is_open()) 
    {
        std::cerr << "Error: Could not open input file.\n";
        return;
    }
    if (infile.peek() == std::ifstream::traits_type::eof()) 
    {
        std::cerr << "Warning: Input file is empty.\n";
    }

    std::ofstream outfile((inputFile + ".replace").c_str());
    if (!outfile.is_open()) 
    {
        std::cerr << "Error: Could not create output file.\n";
        infile.close();
        return;
    }

    std::string line;
    bool found = false;

    while (std::getline(infile, line)) 
    {
        size_t pos = 0;
        while (true) 
        {
            pos = line.find(s1, pos);
            if (pos == std::string::npos)
                break;
            found = true;
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outfile << line << std::endl;
    }

    infile.close();
    outfile.close();

    if (!found)
    {
        std::cout << "Warning: The string '" << s1 << "' was not found in the file." << std::endl;
    }
    else
    {
        std::cout << "Done." << std::endl;
    }
}