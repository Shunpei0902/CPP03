/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:27:10 by sasano            #+#    #+#             */
/*   Updated: 2025/01/19 02:06:29 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavtrap("Scavtrap");
    ScavTrap scavtrap2(scavtrap);
    ScavTrap scavtrap3 = scavtrap;

    scavtrap.attack("enemy");
    scavtrap.takeDamage(5);
    scavtrap.beRepaired(3);
    scavtrap.guardGate();
    return (0);
}

