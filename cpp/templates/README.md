# 🔧 Lesson: Templates in C++

Templates allow us to write **generic code** that works with many types.
Instead of writing the same function or class for `int`, `double`, `std::string`, etc., we can write one **template** that adapts automatically.

---

## 🎯 Learning Goals

By the end of this lesson, you will:

* Understand what a **function template** is.
* Create and use **class templates**.
* Learn why templates are useful in **generic programming**.
* Practice writing type-safe, reusable code.

---

## 🥇 Step 1: The Problem Without Templates

Imagine writing a function to return the maximum of two numbers:

```cpp
int maxInt(int a, int b) {
    return (a > b) ? a : b;
}

double maxDouble(double a, double b) {
    return (a > b) ? a : b;
}
```

This works, but it’s **repetition**. What if we want `max` for `char`, `float`, or `std::string`?
👉 We’d have to keep rewriting!

---

## 🥈 Step 2: Function Templates

A template lets us write this **once** for all types:

```cpp
#include <iostream>
#include <string>

template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << myMax(3, 7) << "\n";          // ints
    std::cout << myMax(3.5, 2.1) << "\n";      // doubles
    std::cout << myMax(std::string("A"), std::string("B")) << "\n"; // strings
}
```

✅ Output:

```
7
3.5
B
```

Notice:

* `template <typename T>` defines a **type parameter** `T`.
* `myMax` works with **any type that supports `>`**.

---

## 🥉 Step 3: Class Templates

Templates also work with **classes**.

Example: a simple generic container:

```cpp
#include <iostream>

template <typename T>
class Box {
private:
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
};

int main() {
    Box<int> intBox(42);
    Box<std::string> strBox("Hello");

    std::cout << intBox.getValue() << "\n";   // 42
    std::cout << strBox.getValue() << "\n";   // Hello
}
```

✅ One class, many types.

---

## 🏗️ Step 4: Templates with Multiple Parameters

We can use more than one type parameter:

```cpp
template <typename T, typename U>
class Pair {
public:
    T first;
    U second;
    Pair(T a, U b) : first(a), second(b) {}
};

int main() {
    Pair<std::string, int> student("Alice", 20);
    std::cout << student.first << " is " << student.second << " years old.\n";
}
```

✅ Output:

```
Alice is 20 years old.
```

---

## 🔍 Exercises

1. Write a **function template** `minValue(T a, T b)` that returns the smaller of two values.

2. Create a **class template** `Stack<T>` with methods `push()`, `pop()`, and `top()`.

    * Test it with `int` and `std::string`.

3. Challenge: Write a **Pair<T, U>** template class that has a method `print()` which prints both values.

---

## 📚 Summary

* **Templates** = write code once, reuse it for many types.
* **Function templates**: generic functions (`myMax`).
* **Class templates**: generic classes (`Box`, `Stack`, `Pair`).
* Templates are the basis of the **Standard Template Library (STL)** in C++.