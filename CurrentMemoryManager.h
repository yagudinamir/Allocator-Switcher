#pragma once
#include "CMemoryAllocationRedefinition.h"

class CurrentMemoryManager {
    CurrentMemoryManager() = delete;
    CurrentMemoryManager(const CurrentMemoryManager& other) = delete;
    CurrentMemoryManager(CurrentMemoryManager&& other) = delete;
    CurrentMemoryManager& operator=(const CurrentMemoryManager& other) = delete;
    CurrentMemoryManager& operator= (CurrentMemoryManager&& other) = delete;
    ~CurrentMemoryManager() = delete;
protected:
    static void* Allocate(std::size_t n) {
        return ::operator new(n);
    }

    static void Free(void* ptr) {
        ::operator delete(ptr);
    }
};