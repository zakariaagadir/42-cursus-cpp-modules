#include "ScavTrap.hpp"




ScavTrap::ScavTrap(const std::string& nam):ClapTrap(nam){
    std::cout<<"ScavTrap constructor called" << std::endl;
    sethpoints(100);
    setepoints(50);
    setadamage(20);
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getname() << " is now in Gate keeper mode." << std::endl;
}


void    ScavTrap::attack(const std::string& target){
    if (this->gethpoints() <= 0) {
        std::cout << "ScavTrap " << this->getname() << " cannot attack, it has no hit points left!" << std::endl;
        return;
    }
    if (this->getepoints() <= 0) {
        std::cout << "ScavTrap " << this->getname() << " cannot attack, it has no energy points left!" << std::endl;
        return;
    }

    this->setepoints(getepoints() - 1);
    std::cout << "ScavTrap " << this->getname() << " attacks " << target << ", causing " << this->getadamage() << " points of damage!" << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout<<"ScavTrap deconstructor called" << std::endl;
}













