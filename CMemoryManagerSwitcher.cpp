#include "CMemoryManagerSwitcher.h"

bool CStackOfManagers::is_any_set = false;
CMemoryManagerSwitcher* CStackOfManagers::ManagersStack = nullptr;

CMemoryManagerSwitcher::CMemoryManagerSwitcher(IMemoryManager *manager_) {
    switching_manager = manager_;
    previous = CStackOfManagers::GetCurrentManager();
    CStackOfManagers::SetManager(this);
}

CMemoryManagerSwitcher::~CMemoryManagerSwitcher() {
        CStackOfManagers::DeleteManager();
}
