#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}

    void introduce() {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
    }
};

class Student : public Person {
public:
    std::string major;

    Student(std::string n, int a, std::string m)
        : Person(n, a), major(m) {}

    void study() {
        std::cout << name << " is studying " << major << ".\n";
    }
};

int main() {
    Student s("Alice", 20, "Computer Science");

    s.introduce();  // from Person
    s.study();      // from Student
}