#pragma once
#include <iostream>

class IMemoryManager {
public:
    virtual void Free(void* ptr) = 0;
    virtual void* Alloc(size_t n) = 0;
//    virtual void Name() = 0;
};