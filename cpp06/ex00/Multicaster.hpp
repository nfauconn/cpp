#ifndef MULTICASTER_HPP
# define MULTICASTER_HPP

# include <string>
# include <iostream>
# include <stdlib.h>
# include <stdio.h>
# include <cstddef>
# include <bits/stdc++.h>
# include "colors.hpp"

class Multicaster {

	public:

		// CONSTRUCTOR DESTRUCTOR ASSIGNMENT 
		Multicaster ();
		Multicaster (Multicaster const& original);
		virtual ~Multicaster ();
		Multicaster& operator= (Multicaster const& rhs);

		// GETTER
		int				getType () const;
		char			getCharCast () const;
		int				getIntCast () const;
		double			getDoubleCast () const;
		float			getFloatCast () const;

		// OTHER MB FUNCTIONS
		void			convert (std::string const& input);
	
	private:

		enum e_type {
			ischar = 0,
			isint,
			isfloat,
			isdouble
		};

		int				_type;
		char			_char_cast;
		int				_int_cast;
		float			_float_cast;
		double			_double_cast;
		
		void			convert (char c);
		void			convert (int i);
		void			convert (double d);
		void			print () const;
		
	public:

		class WrongArgument : public std::exception {

			virtual char const*	what () const throw ();
		};
		class InvalidInput : public std::exception {

			virtual char const*	what () const throw ();
		};
		class NonDisplayableChar : public std::exception {

			virtual char const*	what () const throw ();
		};
};


# endif