# Lesson: Enums in C++

In this lesson, we’ll explore **enums** in C++ — a way to represent a small, fixed set of values (like states, categories, or labels).

---

## Learning Goals

By the end of this lesson, you will:

* Understand what an **enum** is.
* Use enums to represent categories or states.
* Learn the difference between **classic enums** and **enum classes**.
* Combine enums with classes for more expressive code.

---

## Step 1: What is an Enum?

An **enum** (short for *enumeration*) is a type with a limited set of named values.

Example: traffic light states.

```cpp
#include <iostream>

enum TrafficLight {
    Red,
    Yellow,
    Green
};

int main() {
    TrafficLight light = Red;

    if (light == Red) {
        std::cout << "Stop!\n";
    }

    return 0;
}
```

Output:

```
Stop!
```

---

## Step 2: The Problem with Classic Enums

Classic enums are really just integers under the hood.
This can cause problems:

```cpp
enum TrafficLight { Red, Yellow, Green };
enum Weather { Sunny, Rainy, Cloudy };

TrafficLight light = Red;
Weather w = Sunny;

if (light == w) {   // ✅ Compiles, but makes no sense!
    std::cout << "Light matches weather?!\n";
}
```

This is why **C++11 introduced `enum class`**.

---

## Step 3: Scoped Enums (`enum class`)

An `enum class` keeps its values scoped and type-safe.

```cpp
#include <iostream>

enum class TrafficLight { Red, Yellow, Green };

int main() {
    TrafficLight light = TrafficLight::Red;

    if (light == TrafficLight::Red) {
        std::cout << "Stop!\n";
    }

    // Error: no accidental mixing with other enums
    // if (light == Sunny) { ... }   ❌ Won't compile

    return 0;
}
```

Cleaner, safer, and recommended in modern C++.

---

## Step 4: Enums with Classes

Enums often make sense **inside a class** to represent states.

Example:

```cpp
#include <iostream>
#include <string>

class Person {
public:
    enum class Mood { Happy, Sad, Angry };

    Person(std::string n, Mood m) : name(n), mood(m) {}

    void describeMood() {
        std::cout << name << " is ";
        switch (mood) {
            case Mood::Happy: std::cout << "smiling.\n"; break;
            case Mood::Sad:   std::cout << "feeling down.\n"; break;
            case Mood::Angry: std::cout << "angry!\n"; break;
        }
    }

private:
    std::string name;
    Mood mood;
};

int main() {
    Person p("Cillian", Person::Mood::Happy);
    p.describeMood();
}
```

Output:

```
Cillian is smiling.
```

---

## Exercises

1. Write an enum `Day` with values for all days of the week.

    * Print a different message depending on the day.

2. Write a `Car` class and add a `FuelType` enum (`Petrol`, `Diesel`, `Electric`).

    * Print it out in a `printInfo()` method.

3. Challenge: Create a `GameCharacter` class with an enum `State` (`Idle`, `Running`, `Jumping`).

    * Write a method `updateState()` that changes and prints the state.

---

## Summary

* **Enums** let you define a type with fixed values.
* **Classic enums** act like integers → less safe.
* **Scoped enums (`enum class`)** are modern and type-safe.
* Enums work great with **classes** to represent states or categories.

