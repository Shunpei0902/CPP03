/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:16:04 by sasano            #+#    #+#             */
/*   Updated: 2025/01/19 03:11:57 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Defult"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Constructor for " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    _name = copy._name;
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        this->_energyPoints --;
    }
    else if (this->_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
    else if (this->_energyPoints <= 0)
        std::cout << "ClapTrap " << _name << " has no energy and cannot attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints > amount)
    {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    }
    else if (this->_hitPoints > 0)
    {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
    
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0 && this->_hitPoints + amount <= 10)
    {
        this->_hitPoints += amount;
        std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
        this->_energyPoints --;
    }
    else if (this->_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired!" << std::endl;
    else if (this->_energyPoints <= 0)
        std::cout << "ClapTrap " << _name << " has no energy and cannot be repaired!" << std::endl;
    else
    {
        this->_hitPoints = 10;
        std::cout << "ClapTrap" << _name << " is repaired fully!" << std::endl;
    }
}
