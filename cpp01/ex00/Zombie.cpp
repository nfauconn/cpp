/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:45:06 by nfauconn          #+#    #+#             */
/*   Updated: 2023/01/26 17:34:31 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce (void)
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie (void)
{
	_name = "";
}

Zombie::Zombie (std::string name)
{
	_name = name;
}

Zombie::~Zombie (void)
{
	std::cout << _name << " destroyed" << std::endl;
}