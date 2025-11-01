#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    private:
        std::string name;
        unsigned int hpoints;
        unsigned int epoints;
        unsigned int adamage;
    public:
        ClapTrap(const std::string& nam);
        ClapTrap(const ClapTrap& other);
        unsigned int gethpoints() const;
        unsigned int getepoints() const;
        unsigned int getadamage() const;
        const std::string& getname() const;
        void sethpoints(unsigned int other);
        void setepoints(unsigned int other);
        void setadamage(unsigned int other);
        void setname(const std::string& other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap& operator=(const ClapTrap &other);
        ~ClapTrap();
};



#endif