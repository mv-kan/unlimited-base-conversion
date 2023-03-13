#include "chunks.h"

namespace ubc {
    void Chunks::Trim() {
        int i{};
        for (i = _chunks.size() - 1; i >= 0 && _chunks[i] == 0; --i)
            ;
        _chunks.resize(i + 1);
    }
    
    void Chunks::Reserve(size_t n)
    {
        _chunks.reserve(n);
    }

    details::UIntInternal &Chunks::At(size_t i) {
        if (i >= _chunks.size())
            _chunks.resize(i + 1);

        return _chunks[i];
    }

    details::UIntInternal Chunks::At(size_t i) const 
    {
        return _chunks[i];
    }

    // Get number of chunks
    size_t Chunks::Len() const {
        return _chunks.size();
    }
}   