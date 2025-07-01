/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbolanho <jbolanho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:01:36 by jbolanho          #+#    #+#             */
/*   Updated: 2025/07/01 15:01:36 by jbolanho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CopyAndChange.hpp"
#include <iostream>

int main(int argc, char** argv) 
{
    if (argc != 4) 
    {
        std::cerr << "Please try: " << argv[0] << " <filename> <string_to_find> <string_to_replace>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) 
    {
        std::cerr << "Error: The string to be replaced (s1) cannot be empty.\n";
        return 1;
    }

    if (s1 == s2) 
    {
        std::cout << "Warning: s1 and s2 are the same.\n";
    }

    CopyAndChange(filename, s1, s2);

    return 0;
}