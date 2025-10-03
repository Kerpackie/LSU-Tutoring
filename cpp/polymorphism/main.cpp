#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}

    virtual void introduce() = 0;   // pure virtual → abstract class
};

class Student : public Person {
public:
    std::string major;

    Student(std::string n, int a, std::string m)
        : Person(n, a), major(m) {}

    void introduce() override {   // override base method
        std::cout << "Hi, I'm " << name << ", a " << major << " student.\n";
    }
};

class Teacher : public Person {
public:
    std::string subject;

    Teacher(std::string n, int a, std::string s)
        : Person(n, a), subject(s) {}

    void introduce() override {
        std::cout << "Hi, I'm " << name << ", and I teach " << subject << ".\n";
    }
};

int main() {
    std::vector<Person*> people;
    people.push_back(new Student("Alice", 20, "Computer Science"));
    people.push_back(new Teacher("Bob", 40, "Physics"));

    for (Person* p : people) {
        p->introduce();   // Each one behaves differently
    }

    // Cleanup
    for (Person* p : people) delete p;
}