#if !defined(CHUNKS_H)
#define CHUNKS_H

#include <iostream>
#include <vector>

#define UUINT_INTERNAL_BASE 1000000000

namespace ubc
{
    namespace details
    {
        const uint uintInternalBase = UUINT_INTERNAL_BASE;

        using UIntInternal = std::uint64_t;
    }
    class Chunks
    {
    private:
        /*
        Invariants:
        1. _chunks.size has to be at least 1, otherwise invalid uuint_t
        2. _chunks.size has to be trimmed with no tailing zero values
        3. first index is for lower values than last indexes 
        */
        std::vector<details::UIntInternal> _chunks{};
        
        
    public:
        Chunks() = default;

        // get chunk at specific index
        details::UIntInternal &At(size_t i);
        
        // for const objects
        details::UIntInternal At(size_t i) const;

        // Get number of chunks
        size_t Len() const;

        // trim tailing zeros
        void Trim();
    };
} // namespace ubc

#endif // CHUNKS_H
