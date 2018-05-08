#pragma once
#include <iostream>

template< typename Strategy >
class CAllocatedOn{
public:
    void* operator new(std::size_t n) {
        return Strategy::Allocate(n);
    }

    void operator delete(void* ptr) {
        Strategy::Free(ptr);
    }

};