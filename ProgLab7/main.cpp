#include <iostream>
#include <algorithm>
#include <numeric>
#include "circular_buffer.h"


int main()
{
    circular_buffer <int> buffer(9);
    std::cout << "\npush_back from 0 to 8: ";

    for (int i = 0; i < 9; i++)
    {
        buffer.push_back(i);
    }
    print(buffer);

    std::cout << "push_front -375: ";
    buffer.push_front(-375);
    print(buffer);

    std::cout << "x3 pop_back: ";
    buffer.pop_back();
    buffer.pop_back();
    buffer.pop_back();
    print(buffer);

    std::cout << "x2 pop_front: ";
    buffer.pop_front();
    buffer.pop_front();
    print(buffer);

    std::cout << "buffer resize(4): ";
    buffer.resize(4);
    print(buffer);

    auto it = buffer.begin() + 2;
    std::cout << "erase (buffer.begin() + 2): ";
    buffer.erase(it);
    print(buffer);

    std::cout << "insert (buffer.begin() + 2, 7): ";
    buffer.insert(it, 7);
    print(buffer);

    std::cout << "sort (buffer.begin(), buffer.end()): ";
    std::sort(buffer.begin(), buffer.end());
    print(buffer);

    std::cout << "reverse (buffer.begin(), buffer.end()): ";
    std::reverse(buffer.begin(), buffer.end());
    print(buffer);

    std::cout << "accumulate(buffer.begin(), buffer.end(), 0): "
              << std::accumulate(buffer.begin(), buffer.end(), 0) << std::endl;

    std::cout << "buffer.front() = 1000, buffer.back() = 9999: ";
    buffer.front() = 1000;
    buffer.back() = 9999;
    print(buffer);

    std::cout << "x4 buffer.pop_front(): " << std::endl;
    buffer.pop_front();
    buffer.pop_front();
    buffer.pop_front();
    buffer.pop_front();
    std::cout << "buffer.empty(): " << buffer.empty() << std::endl;

    return 0;
}