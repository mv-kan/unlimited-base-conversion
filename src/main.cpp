#include <iostream>
#include "uuint_t.h"

int main() {
	ubc::uuint_t n{18446744073709551615};
	std::cout << ubc::ToStr(n, 10) << std::endl;
	std::cout << ubc::ToStr(n, 16) << std::endl;
	std::cout << ubc::ToStr(n, 16).length() << std::endl;
	std::cout << ubc::ToStr(n, 2) << std::endl;
	std::cout << ubc::ToStr(n, 2).length() << std::endl;
}
