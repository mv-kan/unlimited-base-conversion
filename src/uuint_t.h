#if !defined(UUINT_T_H)
#define UUINT_T_H

#include <iostream>
#include <vector>
#include "chunks.h"

// ubc stands for unlimited base converter
namespace ubc {
    // details is namespace that shouldn't be accessed by a user
    
    /*
    uuint_t - unlimited unsigned int type
    */
    class uuint_t
    {
        
        Chunks _chunks{};
    public:
        uuint_t(size_t initValue = 0);

        uuint_t(std::string_view n, uint base);

        // convert uuint to string in specific base (up to 36)
        std::string ToStr(uint base = 10) const;

        // convert string with specific base (from 2 to 36) to uuint_t
        void FromStr(std::string_view n, uint base);

        // basic math
        void Add(const uuint_t &n);

        void Multiply(const details::UIntInternal n);

        void Divide(details::UIntInternal n);

        details::UIntInternal CalcModule(const details::UIntInternal n) const;
    };
}

#endif