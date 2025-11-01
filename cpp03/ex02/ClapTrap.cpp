#include "ClapTrap.hpp"


ClapTrap::ClapTrap(const std::string& nam):name(nam), hpoints(10), epoints(10), adamage(0){
    std::cout<<"ClapTrap constructor called" << std::endl;

}

unsigned int ClapTrap::gethpoints() const {
    return hpoints;
}

unsigned int ClapTrap::getepoints() const {
    return epoints;
}

unsigned int ClapTrap::getadamage() const {
    return adamage;
}

const std::string& ClapTrap::getname() const {
    return name;
}

void ClapTrap::sethpoints(unsigned int other) {
    hpoints = other;
}

void ClapTrap::setepoints(unsigned int other) {
    epoints = other;
}

void ClapTrap::setadamage(unsigned int other) {
    adamage = other;
}

void ClapTrap::setname(const std::string& other) {
    this->name = other;
}

ClapTrap::ClapTrap(const ClapTrap& other){
    this->setname ( other.getname());
    this->sethpoints ( other.gethpoints());
    this->setepoints ( other.getepoints());
    this->setadamage ( other.getadamage());
}


ClapTrap& ClapTrap::operator=(const ClapTrap &other){
    if(this != &other)
    {
        this->setname ( other.getname());
        this->sethpoints (other.gethpoints());
        this->setepoints (other.getepoints());
        this->setadamage (other.getadamage());
    }
    return (*this);
}

void    ClapTrap::attack(const std::string& target){
    if (this->hpoints <= 0) {
        std::cout << "ClapTrap " << this->name << " cannot attack, it has no hit points left!" << std::endl;
        return;
    }
    if (this->epoints <= 0) {
        std::cout << "ClapTrap " << this->name << " cannot attack, it has no energy points left!" << std::endl;
        return;
    }

    this->epoints--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->adamage << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount){
    if (this->hpoints <= 0) {
        std::cout << "ClapTrap " << this->name << " cannot take Damage, it has no hit points left!" << std::endl;
        return;
    }
    if (this->epoints <= 0) {
        std::cout << "ClapTrap " << this->name << " cannot take Damage, it has no energy points left!" << std::endl;
        return;
    }
    if (this->hpoints > amount) {
            this->hpoints -= amount;
        } else {
            this->hpoints = 0;
        }
        std::cout << "ClapTrap " << this->name << " takes " << amount
                << " points of damage! Hit points are now: " << this->hpoints << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount){
    if (this->hpoints <= 0) {
        std::cout << "ClapTrap " << this->name << " cannot be repaired, it has no hit points left!" << std::endl;
        return;
    }
    if (this->epoints <= 0) {
        std::cout << "ClapTrap " << this->name << " cannot be repaired, it has no energy points left!" << std::endl;
        return;
    }
    this->hpoints += amount;
    this->epoints--;
    std::cout << "ClapTrap " << this->name << " is repaired for " << amount
              << " hit points! Hit points are now: " << this->hpoints << std::endl;
}



ClapTrap::~ClapTrap(){
    std::cout<< "ClapTrap Destructor called" << std::endl;
}
