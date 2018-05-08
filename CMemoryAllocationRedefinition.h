#pragma once
#include "CMemoryManagerSwitcher.h"

void* operator new(std::size_t n) noexcept(false) {
    size_t real_size = n + CStackOfManagers::offset;
    void* ptr;
    void* pointer;

    IMemoryManager* current_manager = nullptr;
    if (CStackOfManagers::is_any_set) {
        current_manager = CStackOfManagers::GetCurrentManager()->switching_manager;
        pointer = current_manager->Alloc(real_size);
//        std::cout << "allocating: ";
        //current_manager->Name();
    } else {
//        std::cout << "\nallocating with malloc\n";
        pointer = std::malloc(real_size);
    }
    IMemoryManager** real = reinterpret_cast<IMemoryManager**>(pointer);
    *real = current_manager;
    ptr = reinterpret_cast<void*>(reinterpret_cast<char*>(pointer) + CStackOfManagers::offset);
    return ptr;
}

void* operator new[](std::size_t n) {
    return ::operator new(n);
}

void operator delete(void* ptr) noexcept {
    void* real_pointer = static_cast<void*>(static_cast<char*>(ptr) - CStackOfManagers::offset);
    IMemoryManager* current_manager = *static_cast<IMemoryManager**>(real_pointer);
    if (current_manager == nullptr) {
        std::free(real_pointer);
        return;
    }
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
