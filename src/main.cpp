#include <iostream>
#include "uuint_t.h"

int main() {
	ubc::uuint_t n{100};
	ubc::uuint_t n2{980};
	std::cout << "hi" << std::endl;
	n.Add(n2);
	n.Multiply(10);
	n.Divide(2);
	std::cout << n.CalcModule(10) << std::endl;
}
