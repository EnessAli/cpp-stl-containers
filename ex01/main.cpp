#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    try {
        std::cout << "=== Basic Test ===" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << "\n=== Large Test (10000 numbers) ===" << std::endl;
        Span bigSpan(10000);
        
        std::srand(std::time(NULL));
        for (int i = 0; i < 10000; i++) {
            bigSpan.addNumber(std::rand() % 50000);
        }
        
        std::cout << "Big span size: " << bigSpan.size() << std::endl;
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

        std::cout << "\n=== Iterator Test ===" << std::endl;
        Span iterSpan(1000);
        std::vector<int> numbers;
        for (int i = 1; i <= 1000; i++) {
            numbers.push_back(i * 2);
        }
        
        iterSpan.addNumbers(numbers.begin(), numbers.end());
        std::cout << "Iterator span size: " << iterSpan.size() << std::endl;
        std::cout << "Shortest span: " << iterSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << iterSpan.longestSpan() << std::endl;

        std::cout << "\n=== Exception Tests ===" << std::endl;
        try {
            sp.addNumber(42);
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        try {
            Span smallSpan(1);
            smallSpan.addNumber(5);
            smallSpan.shortestSpan();
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
