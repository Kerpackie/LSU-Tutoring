//
// Created by Cillian Keogh on 03/10/2025.
//

#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}

    virtual void introduce() {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
    }
};

class Student : public Person {
public:
    std::string major;

    Student(std::string n, int a, std::string m)
        : Person(n, a), major(m) {}

    void introduce() {
        std::cout << "Hi, I'm " << name << ", a " << major << " student.\n";
    }
};

int main() {
    Person* p = new Student("Bob", 21, "Math");
    p->introduce();   // Calls Person::introduce by default ❌
}