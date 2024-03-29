#include "WrongAnimal.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

WrongAnimal::WrongAnimal () : _type ("WrongAnimal") {

	announce ("constructor");
}

WrongAnimal::WrongAnimal (WrongAnimal const& original) {

	*this = original;
	announce ("copy constructor");
}

WrongAnimal::~WrongAnimal () {

	announce ("destructor");
}

// OPERATOR=
WrongAnimal&	WrongAnimal::operator= (WrongAnimal const& rhs) {

	if (this != &rhs)
		_type = rhs.getType ();
	return *this;
}

/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

std::string	const& WrongAnimal::getType () const { return _type; }


/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void	WrongAnimal::announce (std::string const func) const {

	std::cout << "WrongAnimal " << func << " called" << std::endl;
}

void	WrongAnimal::makeSound () const {

	std::cout << "anon wrong animal sound" << std::endl;
}