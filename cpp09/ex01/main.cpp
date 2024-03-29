#include "RPN.hpp"

int	main (int ac, char** av)
{
	try {
		if (ac != 2)
			throw RPN::Error ("Format: ./RPN <expression>");
		RPN::evaluateExpression (av[1]);	
	}
	catch (const std::exception& e) {
		std::cout << e.what () << std::endl;
		return 1;
	}
	return 0;
}
