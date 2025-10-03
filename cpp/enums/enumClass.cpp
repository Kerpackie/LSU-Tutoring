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
