#if !defined(UUINT_T_H)
#define UUINT_T_H

#include <iostream>
#include <vector>
#include "chunks.h"
#include <unordered_map>

// ubc stands for unlimited base converter
namespace ubc
{
    // details is namespace that shouldn't be accessed by a user

    /*
    uuint_t - unlimited unsigned int type
    */
    namespace details
    {
        inline std::string_view NumChar()
        {
            // this is max to 62 base number
            return "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        }
        // this is needed in case we want to change NumChar values and characters
        // CharNum return depends on NumChar() return
        std::unordered_map<char, size_t>& CharNum();
        // we need additional base arg to stay confined in frame of base we converting to or from
        size_t ToInt(char c, size_t base);
        char ToChar(size_t n, size_t base);
    }

    class uuint_t
    {
        Chunks _chunks{};

    public:
        uuint_t(size_t initValue = 0);

        uuint_t(std::string_view n, uint base);

        // basic math
        void Add(const uuint_t &n);

        void Multiply(const details::UIntInternal n);

        void Divide(details::UIntInternal n);

        details::UIntInternal CalcModule(const details::UIntInternal n) const;

        bool IsZero() const;
    };
    // to convert to str, this function alters uuint_t arg, so be careful
    std::string ToStr(uuint_t n, uint base);

    uuint_t FromStr(std::string_view str, uint base);
}

#endif