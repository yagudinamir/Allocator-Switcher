cmake_minimum_required(VERSION 3.8)
project(AllocatorSwitcher)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest-master-2)
include_directories(googletest-master-2/googletest/include)
set(SOURCE_FILES main.cpp IMemoryManager.h CAllocatedOn.h RuntimeHeap.h CurrentMemoryManager.h CMemoryManagerSwitcher.h CMemoryAllocationRedefinition.h CStackAllocator.h DefaultAllocator.h XorList.h CMemoryManagerSwitcher.cpp GoogleTest.h)
add_executable(AllocatorSwitcher ${SOURCE_FILES})
target_link_libraries(AllocatorSwitcher gtest gtest_main)
