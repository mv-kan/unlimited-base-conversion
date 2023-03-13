#include "uuint_t.h"
#include <stdexcept>

namespace ubc {
    uuint_t::uuint_t(size_t initValue)
    {
        size_t len{};
        do
        {
            _chunks.At(len) = initValue % details::uintInternalBase;
            ++len;
            initValue /= details::uintInternalBase;
        } while (initValue);
    }

    uuint_t::uuint_t(std::string_view n, uint base)
    {
        throw std::runtime_error("Not Implemented");
    }

    // convert uuint to string in specific base (up to 36)
    std::string uuint_t::ToStr(uint base) const
    {
        throw std::runtime_error("Not Implemented");
    }

    // convert string with specific base (from 2 to 36) to uuint_t
    void uuint_t::FromStr(std::string_view n, uint base)
    {
        throw std::runtime_error("Not Implemented");
    }

    // basic math
    void uuint_t::Add(const uuint_t &n)
    {
        details::UIntInternal remainder{0};

        if (_chunks.Len() < n._chunks.Len())
        {
            // ...extent *this and fill it with zeros
            for (size_t i = _chunks.Len(); i < n._chunks.Len(); i++)
            {
                _chunks.At(i) = 0;
            }
        }
        for (size_t i = 0; i < std::max(_chunks.Len(), n._chunks.Len()); i++)
        {
            // mLen always bigger or equal to huge.mLen
            details::UIntInternal nChunk{(i < n._chunks.Len()) ? n._chunks.At(i) : static_cast<details::UIntInternal>(0)};

            // sum of remainder, huge value and *this
            details::UIntInternal sum = _chunks.At(i) + nChunk + remainder;

            _chunks.At(i) = sum % details::uintInternalBase;
            remainder = sum / details::uintInternalBase;

            // if no remainder left and huge.mLen is already walked thru then we calculated addition
            // we can return here
            if (!remainder && i >= n._chunks.Len())
                return;
        }

        if (remainder)
        {
            _chunks.At(_chunks.Len()) = remainder;
        }
    }

    void uuint_t::Multiply(const details::UIntInternal n)
    {
        throw std::runtime_error("Not Implemented");
    }

    void uuint_t::Divide(details::UIntInternal n)
    {
        throw std::runtime_error("Not Implemented");
    }

    details::UIntInternal uuint_t::CalcModule(const details::UIntInternal n) const
    {
        throw std::runtime_error("Not Implemented");
    }
}
