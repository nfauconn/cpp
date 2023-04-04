# include "Multicaster.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Multicaster::Multicaster () {

	_param = "";
	_param_len = 0;
	initCasts ();
}

Multicaster::Multicaster (std::string const& string) {

	_param = string;
	_param_len = string.length ();
	initCasts ();
}

Multicaster::Multicaster (Multicaster const& original) {

	*this = original;
}

Multicaster::~Multicaster () {}

Multicaster& Multicaster::operator= (Multicaster const& rhs) {

	if (this != &rhs)
	{
		_c = rhs.getCharCast ();
		_i = rhs.getIntCast ();
		_d = rhs.getDoubleCast ();
		_f = rhs.getFloatCast ();
	}
	return *this;
}

/******************************************************************************************************/
/*	GETTERS SETTERS																	  				  */
/******************************************************************************************************/

char				Multicaster::getCharCast () const { return _c; }

int					Multicaster::getIntCast () const { return _i; }

double				Multicaster::getDoubleCast () const { return _d; }

float				Multicaster::getFloatCast () const { return _f; }

void				Multicaster::initCasts () {

	_type = -1;
	_c = 0;
	_i = 0;
	_d = 0.0;
	_f = 0.0f;
}

/******************************************************************************************************/
/*	CONVERT																							  */
/******************************************************************************************************/

void				Multicaster::convert () {

	switch (_param_len)
	{
		case 0:
			_type = charType;
			break;
		case 1:
			_type = std::isdigit (_param [0]) ? 
						intType 
						: charType;
			break;
		default:
			_param.find_first_not_of ("-0123456789.f") != std::string::npos ?
						strParse () 
						: digitParse ();
	}
	void	(Multicaster::*castType [4]) () = {
													&Multicaster::fromChar, 
													&Multicaster::fromInt,
													&Multicaster::fromFloat,
													&Multicaster::fromDouble
												};
	_type != -1 ? (this->*castType [_type]) () : throw InvalidString ();
}

void				Multicaster::fromChar () {

	std::cout << "from char" << std::endl;
	_c = _param [0];
	_i = static_cast <int> (_c);
	_f = static_cast <float> (_c);
	_d = static_cast <double> (_c);

}

void				Multicaster::fromInt () {

	std::cout << "from int" << std::endl;
	char *p;
	long n = std::strtol (_param.c_str (), &p, 10);
	if (n == )
	_i = std::atoi (_param.c_str ());
	_c = isascii (_i) ? _i : 0;
	_f = static_cast <float> (_i);
	_d = static_cast <double> (_i);
}

void				Multicaster::fromFloat () {

	//_i = std::numeric_limits <int>::max ();//static_cast <int> (_f);
	std::cout << "from float" << std::endl; 
}
void				Multicaster::fromDouble () {

	std::cout << "from double" << std::endl; 
}

void				Multicaster::checkOnlyOne (char c, size_t first) {

	if (_param.find_last_of (c) != first)
		throw InvalidString();
}

void				Multicaster::digitParse () {

	size_t	found;

	std::cout << "Digit param parse" << std::endl;

	found = _param.find_first_of ('-');
	if (found != std::string::npos && found != 0)
		throw InvalidString ();
	
	found = _param.find_first_of ('f'); 
	if (found != std::string::npos)
	{
		if (found != _param_len - 1)
			throw InvalidString ();
		checkOnlyOne ('f', found);
		fromFloat ();
		return;
	}
	found = _param.find_first_of ('.');
	if (found != std::string::npos)
	{
		checkOnlyOne ('.', found);
		fromDouble ();
		return;
	}
	fromInt ();

/* 	if (_param.find_first_of ('.') != _param.find_last_of ('.') 
		|| 
		|| first_found_f != _param_len)

	first_found_f ? fromFloat () : fromDouble (); */
}

void				Multicaster::strParse () {

	std::cout << "Special param parse" << std::endl;
}

/******************************************************************************************************/
/*	displayCasts																							  */
/******************************************************************************************************/

void				Multicaster::displayCasts () {


	try {
		convert ();
		display ();
	}
	catch (std::exception& e) {
		displayException (e);
	}
}

void				Multicaster::display () const {
	
	try {
		std::cout << "Char: ";
		isprint (_c) ?
			std::cout << _c << std::endl
			: throw NonDisplayable ();
	}
	catch (std::exception& e) { 
		displayException (e); 
	}
	try {
		std::cout << "Int: ";
		_i != std::numeric_limits <int> :: max () ?
			std::cout << _i << std::endl
			: throw Impossible ();
	}
	catch (std::exception& e) { 
		displayException (e); 
	}
	std::cout << "Float: " << _f << std::endl;
	std::cout << "Double: " << _d << std::endl;
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

void				Multicaster::displayException (std::exception& e) const {

	std::cout << e.what () << std::endl;
}

char const*			Multicaster::WrongArgument::what () const throw () {

	return ("Wrong argument. Format : ./convert <literal>");
}

char const*			Multicaster::InvalidString::what () const throw () {

	return ("Invalid string. Please enter a literal");
}

char const*			Multicaster::Impossible::what () const throw () {

	return ("Impossible");
}

char const*			Multicaster::NonDisplayable::what () const throw () {

	return ("Non displayable");
}