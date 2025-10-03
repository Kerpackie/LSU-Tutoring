#include <iostream>

int maxInt(int a, int b) {
    return (a > b) ? a : b;
}

double maxDouble(double a, double b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << maxInt(1, 2) << std::endl;
    std::cout << maxDouble(1.0, 2.0) << std::endl;
}