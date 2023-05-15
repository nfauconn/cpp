#include "BitcoinExchange.hpp"
#include <map>
#include <sstream>
#include <string>

//void	parse_file (std::ifstream& file, std::string sep) {
//
//
//}

int	main (int ac, char **av) {

	try {
		if (ac != 2) 
			throw BitcoinExchange::WrongFormat ();
		BitcoinExchange btc (av [1]);
	}
	catch (const std::exception& e) {
		std::cerr << _RED << "Error: " << _END << e.what () << std::endl;
		return 1;
	}
	return 0;
}
