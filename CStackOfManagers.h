#pragma once
#include <stack>
class CMemoryManagerSwitcher;
class CStackOfManagers {
private:
    static std::stack<IMemoryManager*> ManagersStack;
public:
    static bool is_any_set;
    CStackOfManagers() = delete;
    CStackOfManagers(const CStackOfManagers& other) = delete;
    CStackOfManagers(CStackOfManagers&& other) = delete;
    CStackOfManagers& operator=(const CStackOfManagers& other) = delete;
    CStackOfManagers& operator=(CStackOfManagers&& other) = delete;
    static const int offset = sizeof(IMemoryManager*);

    static IMemoryManager* GetCurrentManager() {
        if (ManagersStack.empty()) {
            //std::cout << "\ngetting manager\n";
            return nullptr;
        }
        return ManagersStack.top();
    }

    static void SetManager(IMemoryManager* manager_) {
        //std::cout << "setting manager";
        ManagersStack.push(manager_);
        if (ManagersStack.empty()) {
            //std::cout << " and making flag true";
            is_any_set = true;
        }
    }

    static void DeleteManager() {
        ManagersStack.pop();
        std::cout << ManagersStack.size() << " dectructing STACK \n";
        if (ManagersStack.empty()) {
            is_any_set = false;
        }
    }
};

bool CStackOfManagers::is_any_set = false;
//why???????
std::stack<IMemoryManager*> CStackOfManagers::ManagersStack = std::stack<IMemoryManager*>();