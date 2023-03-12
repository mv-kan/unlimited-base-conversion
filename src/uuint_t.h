#if !defined(UUINT_T_H)
#define UUINT_T_H

#include <iostream>
#include <vector>

#define UINT_INTERNAL_BASE 1000000000

const uint uintInternalBase = UINT_INTERNAL_BASE;

using UIntInternal = std::uint64_t;
/*
uuint_t - unlimited unsigned int type 
*/
class uuint_t  {
    std::vector<UIntInternal> _chunks{};

public:
    // convert uuint to string in specific base (up to 36)
    std::string ToStr(uint base=10);
    
    // basic math 
    void Add(const uuint_t& n);

    void Multiply(const UIntInternal n);

    void Divide(UIntInternal n);

    UIntInternal CalcModule(const UIntInternal n) const;
};

#endif