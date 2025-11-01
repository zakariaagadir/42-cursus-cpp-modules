/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmounji <zmounji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 03:06:12 by zmounji           #+#    #+#             */
/*   Updated: 2025/09/02 03:06:13 by zmounji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP


#include <string>
#include "Weapon.hpp"

class HumanB{
    private:
        std::string name;
        Weapon *weapon;
    public:
        HumanB(const std::string& _name);
        void setWeapon(Weapon& newWeapon);
        void attack();
};



#endif