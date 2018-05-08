#pragma once
#include "IMemoryManager.h"

class CStackOfManagers;

class CMemoryManagerSwitcher {
public:
    CMemoryManagerSwitcher(const CMemoryManagerSwitcher& other) = delete;
    CMemoryManagerSwitcher(CMemoryManagerSwitcher&& other) = delete;
    CMemoryManagerSwitcher& operator=(const CMemoryManagerSwitcher& other) = delete;
    CMemoryManagerSwitcher& operator=(CMemoryManagerSwitcher&& other) = delete;
    explicit CMemoryManagerSwitcher(IMemoryManager* manager_);
    ~CMemoryManagerSwitcher();

    IMemoryManager* switching_manager;
    CMemoryManagerSwitcher* previous;
};

class CStackOfManagers {
private:
    static CMemoryManagerSwitcher* ManagersStack;
public:
    static bool is_any_set;
    CStackOfManagers() = delete;
    CStackOfManagers(const CStackOfManagers& other) = delete;
    CStackOfManagers(CStackOfManagers&& other) = delete;
    CStackOfManagers& operator=(const CStackOfManagers& other) = delete;
    CStackOfManagers& operator=(CStackOfManagers&& other) = delete;
    static const int offset = sizeof(CMemoryManagerSwitcher*);

    static CMemoryManagerSwitcher* GetCurrentManager() {
        if (ManagersStack == nullptr) {
            //std::cout << "\ngetting manager\n";
            return nullptr;
        }
        return ManagersStack;
    }
    static void SetManager(CMemoryManagerSwitcher* manager_) {
        //std::cout << "setting manager";
        if (ManagersStack == nullptr) {
            //std::cout << " and making flag true";
            is_any_set = true;
        }
        ManagersStack = manager_;
    }

    static void DeleteManager() {
        ManagersStack = ManagersStack->previous;
//        std::cout << ManagersStack.size() << " dectructing STACK \n";
        if (ManagersStack == nullptr) {
            is_any_set = false;
        }
    }
};
