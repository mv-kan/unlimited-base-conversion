#include "chunks.h"

namespace ubc
{
    void Chunks::Trim()
    {
        int i{};
        for (i = _chunks.size() - 1; i >= 0 && _chunks[i] == 0; --i)
            ;
        _chunks.resize(i + 1);
    }

    void Chunks::Reserve(size_t n)
    {
        _chunks.reserve(n);
    }

    details::UIntInternal &Chunks::At(size_t i)
    {
        if (i + 1 > _chunks.size())
        {
            if (_chunks.capacity() < i + 1)
            {
                _chunks.reserve(2 * (i + 1)); // I had 2 * capacity() here first, but
                                                  // I think this version is better
            }
            _chunks.resize(i + 1);
        }
        return _chunks[i];
    }

    details::UIntInternal Chunks::At(size_t i) const
    {
        return _chunks[i];
    }

    // Get number of chunks
    size_t Chunks::Len() const
    {
        return _chunks.size();
    }
    // Get number of chunks
    size_t Chunks::Capacity() const
    {
        return _chunks.capacity();
    }
}