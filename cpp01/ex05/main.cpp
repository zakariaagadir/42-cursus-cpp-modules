/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmounji <zmounji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 03:04:37 by zmounji           #+#    #+#             */
/*   Updated: 2025/09/05 11:50:28 by zmounji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "--- Testing DEBUG ---" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "--- Testing INFO ---" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "--- Testing WARNING ---" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "--- Testing ERROR ---" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "--- Testing an invalid level ---" << std::endl;
    harl.complain("INVALID_LEVEL");
    std::cout << std::endl;

    return 0;
}


