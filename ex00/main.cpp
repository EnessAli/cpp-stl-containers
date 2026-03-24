#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    try {
        std::cout << "Testing vector:" << std::endl;
        std::vector<int>::iterator it1 = easyfind(vec, 3);
        std::cout << "Found: " << *it1 << std::endl;

        std::cout << "Testing list:" << std::endl;
        std::list<int>::iterator it2 = easyfind(lst, 30);
        std::cout << "Found: " << *it2 << std::endl;

        std::cout << "Testing not found:" << std::endl;
        easyfind(vec, 99);
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
