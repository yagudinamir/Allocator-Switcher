#pragma once
#include "IMemoryManager.h"
#include "CStackOfManagers.h"

class CMemoryManagerSwitcher {
public:
    CMemoryManagerSwitcher(const CMemoryManagerSwitcher& other) = delete;
    CMemoryManagerSwitcher(CMemoryManagerSwitcher&& other) = delete;
    CMemoryManagerSwitcher& operator=(const CMemoryManagerSwitcher& other) = delete;
    CMemoryManagerSwitcher& operator=(CMemoryManagerSwitcher&& other) = delete;
    explicit CMemoryManagerSwitcher(IMemoryManager* manager_) {
        CStackOfManagers::SetManager(manager_);
    }
    ~CMemoryManagerSwitcher()  {
        CStackOfManagers::DeleteManager();
    }
};