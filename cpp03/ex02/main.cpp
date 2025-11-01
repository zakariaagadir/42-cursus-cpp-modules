#include <iostream>
#include "ClapTrap.hpp" 
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "--- Testing ClapTrap ---" << std::endl;
    ClapTrap clapTrap("CL4P-TP");
    clapTrap.attack("a rusty bolt");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(2);
    std::cout << "--- ClapTrap test complete ---" << std::endl << std::endl;

    std::cout << "--- Testing ScavTrap ---" << std::endl;
    ScavTrap scavTrap("SC4V-TP");
    scavTrap.attack("an intruder");
    scavTrap.takeDamage(15);
    scavTrap.beRepaired(10);
    scavTrap.guardGate();
    std::cout << "--- ScavTrap test complete ---" << std::endl << std::endl;

    std::cout << "--- Testing FragTrap ---" << std::endl;
    FragTrap fragTrap("FR4G-TP");
    std::cout << "FragTrap stats: HP=" << fragTrap.gethpoints()
              << ", EP=" << fragTrap.getepoints()
              << ", AD=" << fragTrap.getadamage() << std::endl;
    fragTrap.highFivesGuys();
    fragTrap.attack("a psycho bandit");
    fragTrap.takeDamage(50);
    fragTrap.beRepaired(25);
    std::cout << "--- FragTrap test complete ---" << std::endl;

    return 0;
}