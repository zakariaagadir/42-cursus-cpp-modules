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


ScavTrap::~ScavTrap(){
    std::cout<<"ScavTrap deconstructor called" << std::endl;
}













