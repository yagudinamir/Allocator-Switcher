#pragma once
#include <iostream>

template< typename Strategy >
class CAllocatedOn{
public:
    CAllocatedOn() = delete;
    CAllocatedOn(const CAllocatedOn& other) = delete;
    CAllocatedOn(CAllocatedOn&& other) = delete;
    CAllocatedOn& operator=(const CAllocatedOn& other) = delete;
    CAllocatedOn& operator=(CAllocatedOn&& other) = delete;
    ~CAllocatedOn() = delete;
 // or public ??
    void* operator new(std::size_t n) {
        return Strategy::Allocate(n);
    }

    void operator delete(void* ptr) {
        Strategy::Free(ptr);
    }

};