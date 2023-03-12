#include "uuint_t.h"
#include <stdexcept>

uuint_t::uuint_t(size_t initValue) {
    throw std::runtime_error("Not Implemented");
}

uuint_t::uuint_t(std::string_view n, uint base){
    throw std::runtime_error("Not Implemented");
}

// convert uuint to string in specific base (up to 36)
std::string uuint_t::ToStr(uint base) {
    throw std::runtime_error("Not Implemented");
}

// convert string with specific base (from 2 to 36) to uuint_t
void uuint_t::FromStr(std::string_view n, uint base) {
    throw std::runtime_error("Not Implemented");
}

// basic math
void uuint_t::Add(const uuint_t &n) {
    throw std::runtime_error("Not Implemented");
}

void uuint_t::Multiply(const UIntInternal n) {
    throw std::runtime_error("Not Implemented");
}

void uuint_t::Divide(UIntInternal n) {
    throw std::runtime_error("Not Implemented");
}

UIntInternal uuint_t::CalcModule(const UIntInternal n) const {
    throw std::runtime_error("Not Implemented");
}