#include "chunks.h"

namespace ubc {
    void Chunks::Trim() {
        int i{};
        for (i = _chunks.size() - 1; i >= 0 && _chunks[i] == 0; --i)
            ;
        _chunks.resize(i + 1);
    }

    details::UIntInternal &Chunks::At(size_t i) {
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