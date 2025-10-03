#include <iostream>


enum TrafficLight {
    Red,
    Yellow,
    Green
};

enum Weather {
    Sunny,
    Rainy,
    Cloudy
};

int main() {
    TrafficLight light = Red;

    if (light == Red) {
        std::cout << "Stop!\n";
    }
    Weather w = Sunny;

    if (light == w) {   // ✅ Compiles, but makes no sense!
        std::cout << "Light matches weather?!\n";
    }


    return 0;
}
