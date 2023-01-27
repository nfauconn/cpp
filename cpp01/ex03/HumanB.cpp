#include "HumanB.hpp"

HumanB::HumanB (std::string name) {
	_name = name;
}

void	setWeapon (Weapon weapon) {
	_weapon = weapon;
}

void	HumanB::attack () {
	std::cout << _name << " attacks with their " << _weapon.getType ();
}