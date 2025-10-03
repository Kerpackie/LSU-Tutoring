//
// Created by Cillian Keogh on 03/10/2025.
//

#include <iostream>

template <typename T>
class Box {
private:
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
};

int main() {
    Box<int> intBox(42);
    Box<std::string> strBox("Hello");

    std::cout << intBox.getValue() << "\n";   // 42
    std::cout << strBox.getValue() << "\n";   // Hello
}
