# 🎭 Lesson: Polymorphism in C++

Polymorphism is another pillar of **object-oriented programming (OOP)**.
It literally means *“many forms”* — the same interface can have different implementations depending on the object.

---

## 🎯 Learning Goals

By the end of this lesson, you will:

* Understand **compile-time vs. runtime polymorphism**.
* Use **virtual functions** for runtime polymorphism.
* Create **abstract classes** with pure virtual functions.
* See how polymorphism lets us treat different objects in a uniform way.

---

## 🥇 Step 1: What is Polymorphism?

* **Compile-time polymorphism** → function overloading, operator overloading.
* **Runtime polymorphism** → achieved through **virtual functions** and **inheritance**.

In C++, when we call a virtual method through a base class pointer or reference, the **derived class version** runs at runtime.

---

## 🥈 Step 2: Virtual Functions

Let’s revisit `Person` and `Student` from last time.

```cpp
#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}

    virtual void introduce() {   // virtual function
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
    }
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
```

---

## 🥉 Step 3: Using Polymorphism

```cpp
int main() {
    Person* p = new Student("Alice", 20, "Computer Science");
    p->introduce();   // ✅ Calls Student::introduce
    delete p;
}
```

Without `virtual`, it would have called `Person::introduce` instead.

---

## 🏗️ Step 4: Abstract Classes

Sometimes we want a class that is just an **interface**, not something we instantiate directly.
We do this with a **pure virtual function** (`= 0`).

```cpp
class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}

    virtual void introduce() = 0;   // pure virtual → abstract class
};
```

Now `Person` is **abstract**:

* You cannot create a `Person` directly.
* Derived classes **must** implement `introduce()`.

```cpp
class Teacher : public Person {
public:
    std::string subject;

    Teacher(std::string n, int a, std::string s)
        : Person(n, a), subject(s) {}

    void introduce() override {
        std::cout << "Hi, I'm " << name << ", and I teach " << subject << ".\n";
    }
};
```

---

## 🏆 Step 5: Polymorphism in Action

We can now store **different objects in the same collection** and call the same method:

```cpp
#include <vector>

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
```

✅ Output:

```
Hi, I'm Alice, a Computer Science student.
Hi, I'm Bob, and I teach Physics.
```

---

## 🔍 Exercises

1. Add a new derived class `Athlete` that has a `sport` field.

    * Override `introduce()` to say `"Hi, I'm X, and I play Y."`.

2. Store `Student`, `Teacher`, and `Athlete` objects in the same `std::vector<Person*>`.

    * Call `introduce()` on each.

3. Bonus: Add a virtual method `getRole()` that returns `"Student"`, `"Teacher"`, or `"Athlete"`.

---

## 📚 Summary

* **Polymorphism** = same interface, different behavior.
* **Virtual functions** let derived classes override behavior at runtime.
* **Abstract classes** define interfaces with **pure virtual functions**.
* You can store and manage different derived types in a **single collection** (e.g., `std::vector<Person*>`).