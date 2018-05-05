#pragma once
#include "IMemoryManager.h"
#include "CMemoryManagerSwitcher.h"

void* operator new(std::size_t n) {
    //std::cout << "1 ";
    size_t real_size = n + CStackOfManagers::offset;
    void* ptr;
    void* pointer;
    IMemoryManager* current_manager = CStackOfManagers::GetCurrentManager();
//    if (current_manager != nullptr) {
//        //std::cout << "allocating: ";
//        current_manager->Name();
//    }

    if (CStackOfManagers::is_any_set) {
        //std::cout << "\nallocating with Allocator\n";
        pointer = current_manager->Alloc(real_size);
    } else {
        //std::cout << "\nallocating with malloc\n";
        pointer = std::malloc(real_size);
    }
    IMemoryManager** real = static_cast<IMemoryManager**>(pointer);
    *real = current_manager;
    ptr = static_cast<void*>(static_cast<char*>(pointer) + CStackOfManagers::offset);
    return ptr;
}

void* operator new[](std::size_t n) {
    return ::operator new(n);
}

void operator delete(void* ptr) noexcept {
    void* real_pointer = static_cast<void*>(static_cast<char*>(ptr) - CStackOfManagers::offset);
    IMemoryManager* current_manager = *static_cast<IMemoryManager**>(real_pointer);
//    if (current_manager != nullptr) {
//        std::cout << "deleting: ";
//        current_manager->Name();
//    }
    if (current_manager == nullptr) {
        std::free(real_pointer);
        //std::cout << "\ndeleting with FREEE\n";
        return;
    }
    //std::cout << "\ndeleting with Allocator\n";
    current_manager->Free(real_pointer);
}

void operator delete[](void* ptr) noexcept {
    void* real_pointer = static_cast<void*>(static_cast<char*>(ptr) - CStackOfManagers::offset);
    IMemoryManager* current_manager = *static_cast<IMemoryManager**>(real_pointer);
    if (current_manager == nullptr) {
        std::free(real_pointer);
        return;
    }
    current_manager->Free(real_pointer);
}
