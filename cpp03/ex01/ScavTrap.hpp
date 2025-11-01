#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"




class ScavTrap : public ClapTrap {
    private:
    public:
        ScavTrap(const std::string& nam);
        void attack(const std::string& target);
        void guardGate();
        ~ScavTrap();
};








#endif

