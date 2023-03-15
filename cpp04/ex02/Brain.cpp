#include "Brain.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Brain::Brain () {

	for (int i = 0; i < 100; i++)
		_ideas [i] = "?";
	announce ("constructor");
}

Brain::Brain (Brain const & original) { 
	
	*this = original;
	announce ("copy constructor");
}

Brain::~Brain () {

	announce ("destructor");
}

// OPERATOR = 
Brain&	Brain::operator= (Brain const & source) {

	if (this != &source)
	{
		for (int i = 100; i != 0; i--)
			_ideas [i] = source.getIdea (i);
	}
	return *this;
}

/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

std::string	Brain::getIdea (int i) const { return _ideas [i]; }

/* ************************************************* */
/* 						OTHER						 */
/* ************************************************* */

void	Brain::announce (std::string const func) const {

	std::cout << "Brain " << func << " called" << std::endl;
}