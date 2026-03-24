#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    std::cout << "=== MutantStack Test ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "Iterating through MutantStack:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    std::cout << "Stack size (copy): " << s.size() << std::endl;

    std::cout << "\n=== std::list comparison ===" << std::endl;
    
    std::list<int> mlist;
    
    mlist.push_back(5);
    mlist.push_back(17);
    
    std::cout << "Back: " << mlist.back() << std::endl;
    
    mlist.pop_back();
    
    std::cout << "Size: " << mlist.size() << std::endl;
    
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    
    std::list<int>::iterator lit = mlist.begin();
    std::list<int>::iterator lite = mlist.end();
    
    ++lit;
    --lit;
    
    std::cout << "Iterating through std::list:" << std::endl;
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "\n=== Reverse Iterator Test ===" << std::endl;
    
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    
    std::cout << "Reverse iteration:" << std::endl;
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    return 0;
}
