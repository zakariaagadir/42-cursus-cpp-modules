/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmounji <zmounji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 03:05:18 by zmounji           #+#    #+#             */
/*   Updated: 2025/09/02 03:05:19 by zmounji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie :: Zombie() : name(""){}
Zombie :: ~Zombie(){
    std::cout<< "deleted" << std::endl;
}
Zombie :: Zombie(std::string name){
    this->name = name;
}

void Zombie :: announce(){
    std::cout<< name ;
    std::cout<< ": BraiiiiiiinnnzzzZ..." << std::endl;
}
