/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmounji <zmounji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 03:06:16 by zmounji           #+#    #+#             */
/*   Updated: 2025/09/02 03:06:17 by zmounji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(const std::string& _type);
        const std::string& getType() const;
        void  setType(const std::string& newType);


};




#endif