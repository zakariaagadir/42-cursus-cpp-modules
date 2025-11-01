#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"




class ScavTrap : public ClapTrap {
    public:
        ScavTrap(const std::string& nam);
        void guardGate();
        ~ScavTrap();
};








#endif

