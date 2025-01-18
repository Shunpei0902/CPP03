/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:59:55 by sasano            #+#    #+#             */
/*   Updated: 2025/01/19 02:05:38 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(), _guardGateMode(false)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _guardGateMode(false)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Constructor for " << this->_name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
    this->_guardGateMode = copy._guardGateMode;
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    this->_name = copy._name;
    this->_hitPoints = copy._hitPoints;
    this->_energyPoints = copy._energyPoints;
    this->_attackDamage = copy._attackDamage;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints --;
    }
    else if (this->_hitPoints <= 0)
        std::cout << "ScavTrap " << this->_name << " is dead and cannot attack!" << std::endl;
    else if (this->_energyPoints <= 0)
        std::cout << "ScavTrap " << this->_name << " has no energy and cannot attack!" << std::endl;
}

void ScavTrap::guardGate()
{
    if (this->_guardGateMode == false)
    {
        std::cout << "ScavTrap " << this->_name << " has entered Gate keeper mode!" << std::endl;
        this->_guardGateMode = true;
    }
    else
        std::cout << "ScavTrap " << this->_name << " has exited Gate keeper mode!" << std::endl;
}