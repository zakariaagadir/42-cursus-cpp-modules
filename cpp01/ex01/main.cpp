/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmounji <zmounji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 03:04:56 by zmounji           #+#    #+#             */
/*   Updated: 2025/09/02 03:04:57 by zmounji          ###   ########.fr       */
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

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return (NULL);
    Zombie* tableau = new Zombie[N];
    while (N-- > 0)
    {
        tableau[N] = Zombie(name);
    }
    return(tableau);
}

// int main(void)
// {
//     int a  = 6;
//     Zombie* test = zombieHorde(a,"zaaaa");

//     while(a--)
//     {
//         test[a].announce();
//     }
//     delete []test ;
//     return (0);
// }
