cmake_minimum_required(VERSION 3.8)
project(AllocatorSwitcher)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp IMemoryManager.h CStackOfManagers.h CAllocatedOn.h RuntimeHeap.h CurrentMemoryManager.h CMemoryManagerSwitcher.h CMemoryAllocationRedefinition.h CStackAllocator.h DefaultAllocator.h XorList.h)
add_executable(AllocatorSwitcher ${SOURCE_FILES})