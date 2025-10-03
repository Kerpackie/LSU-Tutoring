//
// Created by Cillian Keogh on 03/10/2025.
//

#include <iostream>

enum class TrafficLight {
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
    TrafficLight light = TrafficLight::Red;

    if (light == TrafficLight::Red) {
        std::cout << "Stop!\n";
    }
    Weather w = Sunny;


    if (light == w) {   // Makes no sense!
        std::cout << "Light matches weather?!\n";
    }

    return 0;
}