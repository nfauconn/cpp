#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {

	public:
		// CONSTRUCTORS / DESTRUCTOR
		FragTrap ();
		FragTrap (std::string name);
		FragTrap (FragTrap const& original);
		~FragTrap ();
	 
	  	// SETTER
		virtual std::string const	getName () const;
		void	setDefaultHP ();
		void	setDefaultPP ();
		void	setDefaultAD ();

	 	// OPERATORS
		FragTrap&	operator= (ClapTrap const& source);
		
		void	attack (const std::string& target);
		void	highFivesGuys (void);
};


#endif