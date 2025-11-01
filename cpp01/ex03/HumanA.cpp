/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmounji <zmounji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 03:04:45 by zmounji           #+#    #+#             */
/*   Updated: 2025/09/02 03:19:47 by zmounji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>


HumanA::HumanA(const std::string& _name, Weapon& _weapon): name(_name), weapon(_weapon){
}

void HumanA::attack(){
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}