/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmounji <zmounji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 03:04:41 by zmounji           #+#    #+#             */
/*   Updated: 2025/09/02 03:04:42 by zmounji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& _name): name(_name), weapon(NULL){
}

void HumanB::setWeapon(Weapon& newWeapon) {
    weapon = &newWeapon;
}


void HumanB::attack() {
    if (weapon) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " cannot attack, they have no weapon!" << std::endl;
    }
}
