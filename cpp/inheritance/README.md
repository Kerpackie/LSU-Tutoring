# 🏰 Lesson: Inheritance in C++

Inheritance is one of the **four pillars of object-oriented programming (OOP)**:

1. **Encapsulation** – bundling data & behavior together
2. **Abstraction** – hiding complexity behind an interface
3. **Inheritance** – reusing and extending code
4. **Polymorphism** – treating objects of different types in a uniform way

In this lesson, we’ll focus on **inheritance**.

---

## 🎯 Learning Goals

By the end of this lesson, you will:

* Understand **base classes** and **derived classes**.
* Use **`public` inheritance** to reuse code.
* Override base class methods in derived classes.
* Use the `virtual` keyword for **runtime polymorphism**.

---

## 🥇 Step 1: A Base Class

Let’s start with a `Person` class:

```cpp
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
```

---

## 🥈 Step 2: Deriving a Class

Now let’s create a `Student` that **inherits** from `Person`:

```cpp
class Student : public Person {
public:
    std::string major;

    Student(std::string n, int a, std::string m)
        : Person(n, a), major(m) {}

    void study() {
        std::cout << name << " is studying " << major << ".\n";
    }
};
```

Notice:

* `Student` **reuses** `name` and `age` from `Person`.
* The `Student` constructor calls the `Person` constructor using `: Person(n, a)`.

---

## 🥉 Step 3: Using Inheritance

```cpp
int main() {
    Student s("Alice", 20, "Computer Science");

    s.introduce();  // from Person
    s.study();      // from Student
}
```

✅ Output:

```
Hi, I'm Alice and I'm 20 years old.
Alice is studying Computer Science.
```

---

## 🏗️ Step 4: Method Overriding

Suppose `Student` should introduce themselves differently.

```cpp
class Student : public Person {
public:
    std::string major;

    Student(std::string n, int a, std::string m)
        : Person(n, a), major(m) {}

    void introduce() {
        std::cout << "Hi, I'm " << name << ", a " << major << " student.\n";
    }
};
```

✅ The new `introduce()` **overrides** the base class method.

---

## 🏆 Step 5: Polymorphism with `virtual`

If we call methods through a **base class pointer**, by default C++ chooses the base version:

```cpp
Person* p = new Student("Bob", 21, "Math");
p->introduce();   // Calls Person::introduce by default ❌
```

👉 Fix: mark the base class method as **virtual**:

```cpp
class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}

    virtual void introduce() {   // virtual method
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
    }
};
```

Now, runtime chooses the correct override:

```cpp
Person* p = new Student("Bob", 21, "Math");
p->introduce();   // ✅ Calls Student::introduce
```

---

## 🔍 Exercises

1. Create a `Teacher` class that inherits from `Person`.

    * Add a subject (e.g., `"Physics"`).
    * Override `introduce()` to include the subject.

2. Store both `Student` and `Teacher` objects in a `std::vector<Person*>`.

    * Loop over them and call `introduce()`.
    * See how **polymorphism** lets them behave differently!

3. Bonus: Mark `Person` as an **abstract base class** by making `introduce()` a **pure virtual function**:

   ```cpp
   virtual void introduce() = 0;
   ```

   Now you **must** override it in `Student` and `Teacher`.

---

## 📚 Summary

* **Inheritance** lets a class reuse and extend another class.
* Use `: public BaseClass` for inheritance.
* **Overriding** replaces a base method in the derived class.
* Mark methods as `virtual` to enable **runtime polymorphism**.
* Abstract base classes define interfaces (`= 0`) that derived classes must implement.
