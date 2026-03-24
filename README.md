# C++ STL Containers

Advanced use of C++ Standard Template Library containers and algorithms: `std::stack`, `std::map`, `std::set`, and `std::list` — with a focus on the correct container choice for each algorithmic problem.

## Projects

### MutantStack (ex00)
Extends `std::stack` with full iterator support by exposing the underlying `std::deque` iterators:
```cpp
MutantStack<int> mstack;
mstack.push(5);
MutantStack<int>::iterator it = mstack.begin();
// iterate like a vector — impossible with raw std::stack
```

### Span (ex01)
Container holding N integers with `addNumber`, `shortestSpan`, and `longestSpan`:
```cpp
Span sp(10000);
sp.addNumber(begin, end);  // range insert
sp.shortestSpan();         // O(n log n) via sort + adjacent_difference
sp.longestSpan();          // max - min
```

### EasyFind (ex02)
Generic algorithm template that finds a value in any STL container:
```cpp
template <typename T>
typename T::const_iterator easyFind(const T &container, int val) {
    return std::find(container.begin(), container.end(), val);
}
```
Throws `std::exception` if not found.

## Build

```bash
make && ./ex00
```

## Tech Stack

`C++98` `STL` `std::stack` `std::list` `std::map` `std::find` `Iterators`

