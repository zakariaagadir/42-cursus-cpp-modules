#include <iostream>
#include "ClapTrap.hpp"



int main() {
    ClapTrap clapTrap1("Brahim");
    std::cout << "---" << std::endl;

    std::cout << "ClapTrap attacks a target:" << std::endl;
    clapTrap1.attack("Bandit");
    std::cout << "---" << std::endl;

    std::cout << "ClapTrap takes damage:" << std::endl;
    clapTrap1.takeDamage(5);
    std::cout << "---" << std::endl;

    std::cout << "ClapTrap repairs itself:" << std::endl;
    clapTrap1.beRepaired(3);
    std::cout << "---" << std::endl;
    
    std::cout << "Testing energy point constraint:" << std::endl;
    for (int i = 0; i < 11; ++i) {
        clapTrap1.attack("Psycho");
    }
    std::cout << "---" << std::endl;

    std::cout << "Testing hit point constraint:" << std::endl;
    ClapTrap clapTrap2("Fragtrap");
    clapTrap2.takeDamage(12); 
    clapTrap2.attack("Rakk");
    clapTrap2.beRepaired(5); 
    std::cout << "---" << std::endl;

    return 0;
}