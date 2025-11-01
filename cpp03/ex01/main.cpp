#include <iostream>
#include "ClapTrap.hpp"



#include "ScavTrap.hpp"
#include <iostream>

int main() {
    // Test ScavTrap's constructor and inherited behavior
    ScavTrap scavTrap1("brahim");
    std::cout << "---" << std::endl;

    // Test a unique ScavTrap method
    std::cout << "Testing unique ScavTrap function:" << std::endl;
    scavTrap1.guardGate();
    std::cout << "---" << std::endl;

    // Test inherited functionality
    std::cout << "Testing inherited ClapTrap functions:" << std::endl;
    scavTrap1.attack("youssef");
    scavTrap1.takeDamage(5);
    scavTrap1.beRepaired(2);
    std::cout << "---" << std::endl;

    return 0;
}
