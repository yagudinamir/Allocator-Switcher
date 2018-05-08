#pragma once
#include "IMemoryManager.h"

class DefaultAllocator : public IMemoryManager {
public:
    DefaultAllocator() {
        //std::cout << "2 ";
    }
    void* Alloc(std::size_t n) override {
        return std::malloc(n);
    }

    void Free(void* ptr) override {
        std::free(ptr);
    }

//    void Name() override {
//        std::cout << "\n DEFAULT \n";
//    }
};