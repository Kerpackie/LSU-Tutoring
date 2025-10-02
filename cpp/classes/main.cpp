#include <iostream>
#include "Person.h"

class Car {
public:
    std::string make;
    int year;

    Car(const std::string& m, int y) : make(m), year(y) {}

    void printInfo() const {
        std::cout << "Car make: " << make << ", year: " << year << std::endl;
    }
};


int main() {
    Car myCar("Ford", 2018);
    myCar.printInfo();

    Person p1("Cillian", 25);
    p1.sayHello();

    return 0;
}

