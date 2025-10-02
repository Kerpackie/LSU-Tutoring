//
// Created by Cillian Keogh on 02/10/2025.
//

#pragma once
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a);
    void sayHello();
};
