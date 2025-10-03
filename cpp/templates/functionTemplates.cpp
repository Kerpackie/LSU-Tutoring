//
// Created by Cillian Keogh on 03/10/2025.
//

#include <iostream>
#include <string>

template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << myMax(3, 7) << "\n";          // ints
    std::cout << myMax(3.5, 2.1) << "\n";      // doubles
    std::cout << myMax(std::string("A"), std::string("B")) << "\n"; // strings
}
