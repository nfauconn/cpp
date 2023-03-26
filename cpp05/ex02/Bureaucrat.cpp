# include "Bureaucrat.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Bureaucrat::Bureaucrat (std::string const name, int grade) : _name (name) {

	checkGrade (grade);
	_grade = grade;
	if (_verbose)
		announce ("Constructor");
}

Bureaucrat::Bureaucrat (Bureaucrat const& original) : _name (original.getName ()) {

	_grade = original.getGrade ();
	if (_verbose)
		announce ("Copy constructor");
}

Bureaucrat::~Bureaucrat () {

	if (_verbose)
		announce ("Destructor");
}

Bureaucrat& Bureaucrat::operator= (Bureaucrat const& rhs) {

	if (this != &rhs)
	{
		std::cout << "Warning : name not assigned to '" << rhs.getName () << "' coz name is const" << std::endl;
		_grade = rhs.getGrade ();
		if (_verbose)
			announce ("Assignment operator");
	}
	return *this;
}

/******************************************************************************************************/
/*	GETTERS SETTERS																					  */
/******************************************************************************************************/

std::string const&	Bureaucrat::getName () const {

	return ((std::string const &) _name);
}

int const&			Bureaucrat::getGrade () const {

	return ((int const &) _grade);
}

void				Bureaucrat::lowerGrade () {

	std::cout << "Lowering grade of " << _name << "..." << std::endl;
	checkGrade (++_grade);
	announce ("Lowered grade");
}

void				Bureaucrat::upperGrade () {

	std::cout << "Uppering grade of " << _name << "..." << std::endl;
	checkGrade (--_grade);
	announce ("Uppered grade");
}

/******************************************************************************************************/
/*	PUBLIC MB FUNC																					  */
/******************************************************************************************************/

void	Bureaucrat::signForm (AForm& form) {

	try {

		form.beSigned (*this);
		std::cout << _GREEN << "Signed" << _END << ": " << form.getName () << " by bureaucrat " << _name << std::endl;
	}
	catch (std::exception& e) {

		std::cout << _RED << "Not signed" << _END << ": " << form.getName () << " by bureaucrat " << _name << " coz grade too low >_<" << std::endl;
	}
}

void	Bureaucrat::executeForm (AForm& form) const {

	try {
		form.execute (*this);
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}
}

/******************************************************************************************************/
/*	PRIVATE UTILS																					  */
/******************************************************************************************************/

void		Bureaucrat::checkGrade (int grade) const {

	if (grade < highest_grade)
		throw Bureaucrat::GradeTooHighException ();
	else if (grade > lowest_grade)
		throw Bureaucrat::GradeTooLowException ();
}

void		Bureaucrat::announce (std::string const func) const {

	std::cout << _GREEN << func << _END 
		<< ": " << _name << " bureaucrat, grade " << _grade << std::endl;
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

const char*	Bureaucrat::GradeTooHighException::what () const throw () {

	return ("Bureaucrat: Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what () const throw () {

	return ("Bureaucrat: Grade too low");
}

/******************************************************************************************************/
/*	DISPLAY																							  */
/******************************************************************************************************/

std::ostream&	operator<< (std::ostream& o, Bureaucrat const& toDisplay) {

	o << toDisplay.getName () << ", bureaucrat grade " << toDisplay.getGrade ();
	return o;
}
