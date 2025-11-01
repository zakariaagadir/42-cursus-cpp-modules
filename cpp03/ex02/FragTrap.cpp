#include "FragTrap.hpp"




FragTrap::FragTrap(const std::string& nam):ClapTrap(nam){
    std::cout<<"ScavTrap constructor called" << std::endl;
    sethpoints(100);
    setepoints(100);
    setadamage(30);
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->getname() << " requests a high five!" << std::endl;
}


FragTrap::~FragTrap(){
    std::cout<< "FragTrap Destructor called" << std::endl;
}













