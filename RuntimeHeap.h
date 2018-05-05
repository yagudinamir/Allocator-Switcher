#pragma once
#include <iostream>
#include <memory>
class RuntimeHeap {
public:
    RuntimeHeap() = delete;
    RuntimeHeap(const RuntimeHeap& other) = delete;
    RuntimeHeap(RuntimeHeap&& other) = delete;
    RuntimeHeap& operator=(const RuntimeHeap& other) = delete;
    RuntimeHeap& operator=(RuntimeHeap&& other) = delete;
protected:
    static void* Allocate(std::size_t n) {
        if (n == 0) {
            n = 1;
        }
        return ::malloc(n);
    }

    static void Free(void* ptr) {
        if (ptr)
            ::free(ptr);
    }
};