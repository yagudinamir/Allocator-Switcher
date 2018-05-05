#include "CMemoryAllocationRedefinition.h"
#include "CAllocatedOn.h"
#include "DefaultAllocator.h"
#include "CStackAllocator.h"
#include <vector>
#include <ctime>


class Edge{
public:
    int x;
    int y;
    Edge() {
        x = 0;
        y = 0;
    }
};


class Node {
private:
    std::vector<Edge> numbers;
public:
    Node() {
        for (int i = 0; i < 100000; ++i ) {
            numbers.emplace_back();
        }
    }
};

int main() {
    std::vector<int> MyList1;
    std::vector<int> MyList2;
    std::vector<int> MyList3;
    std::vector<int> MyList4;

    StackAllocator<int>* stackAllocator = new StackAllocator<int>();
    CMemoryManagerSwitcher* SwitcherToStack = new CMemoryManagerSwitcher(stackAllocator);
    clock_t t;
    t = clock();
//    for (int i = 0; i < 100000; ++i) {
//        MyList2.push_back(i);
//    }
    Node* node1 = new Node();
    t = clock() - t;
    std::cout << "With Stack Allocator: \n" << t << std::endl;

    DefaultAllocator* defAllocator = new DefaultAllocator();
    //std::cout << "\nSwitcherToDefaultGoes\n";
    CMemoryManagerSwitcher* SwitcherToDefault = new CMemoryManagerSwitcher(defAllocator);
    //std::cout << "OK" << std::endl;
    t = clock();
//    for (int i = 0; i < 100000; ++i) {
//        MyList1.push_back(i);
//    }
    Node* node2 = new Node();
    t = clock() - t;
    std::cout << "With Default Allocator: \n" << t << std::endl;

    delete SwitcherToDefault;
    t = clock();
//    for (int i = 0; i < 100000; ++i) {
//        MyList3.push_back(i);
//    }
    Node* node3 = new Node();
    t = clock() - t;
    std::cout << "With Stack Allocator: \n" << t << std::endl;

    delete SwitcherToDefault;
    t = clock();
//    for (int i = 0; i < 100000; ++i) {
//        MyList3.push_back(i);
//    }
    Node* node4 = new Node();
    t = clock() - t;
    std::cout << "With Initial Allocator: \n" << t << std::endl;


//    for (int i = 0; i < MyList1.size(); ++i) {
//        std::cout << MyList1[i] << " ";
//    }
//    std::cout << std::endl;
//
//    for (int i = 0; i < MyList2.size(); ++i) {
//        std::cout << MyList2[i] << " ";
//    }
//    std::cout << std::endl;
//
//    for (int i = 0; i < MyList3.size(); ++i) {
//        std::cout << MyList3[i] << " ";
//    }
    std::cout << std::endl;




    return 0;
}