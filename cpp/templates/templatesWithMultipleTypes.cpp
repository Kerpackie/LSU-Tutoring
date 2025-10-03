//
// Created by Cillian Keogh on 03/10/2025.
//

#include <iostream>
#include <string>

template <typename T, typename U>
class Pair {
public:
    T first;
    U second;
    Pair(T a, U b) : first(a), second(b) {}
};

int main() {
    Pair<std::string, int> student("Alice", 20);
    std::cout << student.first << " is " << student.second << " years old.\n";
}
