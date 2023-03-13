#include <iostream>
#include "uuint_t.h"

#include <string>
int main() {
	std::string str{};
	std::cin >> str;
	ubc::uuint_t num = std::move(ubc::FromStr(str, 10));
	std::cin >> str;
	size_t n = std::stoi(str);

	num.Multiply(n);
	std::cout << ubc::ToStr(num, 2) << std::endl;
}
