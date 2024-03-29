#include "PmergeMe.hpp"

int	main (int ac, char** av)
{
	try {
		if (ac < 2)
			throw PmergeMe::Error ("Format: ./PmergeMe <positive integer sequence>");	
		PmergeMe s;
        s.checkArgs(ac, av);
		s.sort (ac, av);
	}
	catch (const std::exception& e) {
		std::cout << _RED << "Error: " << _END << e.what () << std::endl;
		return 1;
	}
	return 0;
}
