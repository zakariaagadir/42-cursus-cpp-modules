/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmounji <zmounji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 03:05:14 by zmounji           #+#    #+#             */
/*   Updated: 2025/09/02 03:05:15 by zmounji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
     Zombie* zombie1 = new Zombie(name);
     return (zombie1);
}

void randomChump( std::string name )
{
    Zombie* zombie1 = newZombie(name);

    zombie1->announce();
    
    delete(zombie1);
}

// int main(void)
// {
//     randomChump("zaaaa");

//     return (0);
// }
