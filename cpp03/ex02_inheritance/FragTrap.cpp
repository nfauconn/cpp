#include "FragTrap.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

FragTrap::FragTrap () {

	_name = "AnonFrag";
	_HP = 100;
	_PP = 100;
	_AD = 30;
	_maxHP = _HP;
	std::cout << "...FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap (std::string name) {

	_name = name;
	_HP = 100;
	_PP = 100;
	_AD = 30;
	_maxHP = _HP;
	std::cout << "...FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap (FragTrap const& original) : ClapTrap (original) {

	*this = original;
	std::cout << "...FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap () {

	std::cout << "...FragTrap destructor called" << std::endl;
}


/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
FragTrap&	FragTrap::operator= (ClapTrap const& source) {

	if (this != &source)
	{
		_name = source.getName ();
		_HP = source.getHP ();
		_PP = source.getPP ();
		_AD = source.getAD ();
	}
	return *this;
}

/* ************************************************* */
/* 						NON MB FUNCTIONS			 */
/* ************************************************* */

void	FragTrap::attack (const std::string& target)
{
	if (_HP)
		_PP-- ?
			std::cout << _name << " throw a bomb on " << target << std::endl
			: std::cout << _name << " cant attack " << target << " coz no PP anymore" << std::endl;
	else
		std:: cout << _name << " tries to attack "<< target << " but they are already KO" << std::endl;
}

void	FragTrap::highFivesGuys (void) {

	_HP ?
		std::cout << _name << " does a High Five \n\t\t⤷ it makes them happy" << std::endl
		: std:: cout << _name << " tries to do a High Five to their friend but they are already KO" << std::endl;
}