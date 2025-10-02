# 🚀 Introduction to C++ Classes

This tutorial introduces **object-oriented programming (OOP)** in C++.
We’ll start with simple examples, then refactor into multiple files using **header files** and **source files**.

---

## Learning Goals

By the end of this lesson, you will:

* Understand what a **class** is.
* Create **objects** from a class.
* Use **constructors** and **methods**.
* Split code into **header (`.h`)** and **source (`.cpp`)** files.
* Compile and run a **multi-file C++ project**.

---

## Step 1: Defining a Simple Class (All in One File)

Let’s define a `Car` class inside `main.cpp`.

```cpp
#include <iostream>
#include <string>

// Step 1: Define a class
class Car {
public:
    std::string make;
    int year;

    Car(const std::string& m, int y) : make(m), year(y) {}

    void printInfo() const {
        std::cout << "Car make: " << make << ", year: " << year << std::endl;
    }
};

// Step 2: Use the class
int main() {
    Car myCar("Ford", 2018);
    myCar.printInfo();
    return 0;
}
```

**Compile & run:**

```bash
g++ main.cpp -o car_program
./car_program
```

**Expected output:**

```
Car make: Ford, year: 2018
```

---

## Step 2: Adding Another Class

Now, add a `Person` class to the same file:

```cpp
class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}

    void sayHello() {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
    }
};

int main() {
    Car myCar("Ford", 2018);
    myCar.printInfo();

    Person p1("Cillian", 25);
    p1.sayHello();
}
```

Compile again and notice the new output.

---

## Step 3: Splitting into Multiple Files

Large programs shouldn’t keep everything in one file.
We split our class into **declaration** (`.h`) and **implementation** (`.cpp`).

### `Person.h` (Header File)

```cpp
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a);  // constructor declaration
    void sayHello();               // method declaration
};

#endif
```

### `Person.cpp` (Source File)

```cpp
#include "Person.h"
#include <iostream>

Person::Person(std::string n, int a) : name(n), age(a) {}

void Person::sayHello() {
    std::cout << "Hi, I'm " << name << " and I'm " << age << " years old.\n";
}
```

### `main.cpp`

```cpp
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
```

---

## Step 4: Compiling Multiple Files

Now compile **both source files** together:

```bash
g++ main.cpp Person.cpp -o program
./program
```

Output:

```
Car make: Ford, year: 2018
Hi, I'm Cillian and I'm 25 years old.
```

---

## Step 5: Why Use Header Files?

* **Organization:** Easier to read and maintain.
* **Reusability:** Any program can use `Person` by including `Person.h`.
* **Scalability:** Large projects often have hundreds of classes.

---

## Exercises

1. Add a new method `haveBirthday()` to `Person` that increases `age` and prints a message.
2. Move the `Car` class into its own `Car.h` and `Car.cpp` files.
3. Make a `Person` own a `Car`:

    * Add a `Car` field to `Person`.
    * Print both the person’s info and their car’s info.

---

## Summary

* A **class** defines **data** (fields) and **behavior** (methods).
* **Objects** are instances of classes.
* **Constructors** initialize objects.
* Use **headers (.h)** for declarations.
* Use **source files (.cpp)** for implementations.
* Compile all `.cpp` files together into one program.

---

This is the foundation of **object-oriented programming in C++**. From here, you can explore **inheritance, polymorphism, and encapsulation**.
