#include <iostream>
#include "Temp_literals.h"

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "Temperature in Celsius (from Kelvin): " << a << std::endl;
    std::cout << "Temperature in Celsius (from Fahrenheit): " << b << std::endl;

    return 0;
}
