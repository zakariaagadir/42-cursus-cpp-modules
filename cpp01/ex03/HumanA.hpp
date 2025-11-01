/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmounji <zmounji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 03:05:39 by zmounji           #+#    #+#             */
/*   Updated: 2025/09/02 03:05:40 by zmounji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP


#include <string>
#include "Weapon.hpp"

class HumanA{
    private:
        std::string name;
        Weapon& weapon;
    public:
        HumanA(const std::string& _name, Weapon& _weapon);
        void attack();
};



#endif