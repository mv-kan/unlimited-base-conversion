#include <iostream>
#include "uuint_t.h"
#include <string>

int main(int argc, char** argv) {

	if (argc != 4) {
		std::cerr << "too many or too few arguments are passed. \n\nubc [the number you want to convert] [the number base] [result base]\nexample1:\tubc 10101 2 10\noutput1:\t21\n\nexample2:\tubc AAAABBBBCCCCDDDD 16 36\noutput2:\t2LFLJC63L8XR1\n\nexample3:\tubc FFFF 16 10\noutput3:\t65535\n\nexample4:\tubc Hello 36 10\noutput4:\tError (because lowercase letters are not present in 36 base only uppercase)" << std::endl;
		return 1;
	}

	std::string _numInput{argv[1]};
	std::string _inputBase{argv[2]};
	std::string _outputBase{argv[3]};

	size_t inputBase = std::stoul(_inputBase);
	size_t outputBase = std::stoul(_outputBase);
	try {
		ubc::uuint_t n = ubc::FromStr(_numInput, inputBase);
		std::cout << ubc::ToStr(n, outputBase) << std::endl;
	} catch(const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
