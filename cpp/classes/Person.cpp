//
// Created by Cillian Keogh on 02/10/2025.
//

#include "Person.h"

#include "Person.h"
#include <iostream>

Person::Person(std::string n, int a) : name(n), age(a) {}

void Person::sayHello() {
    std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
}

