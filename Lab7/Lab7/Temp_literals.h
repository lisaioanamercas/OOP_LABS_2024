#pragma once
//header guards:
#ifndef TEMP_LITERALS_H
#define TEMP_LITERALS_H

constexpr float operator"" _Fahrenheit(unsigned long long int value) {
    return (value - 32.0) * 5.0 / 9.0;
}
constexpr float operator"" _Kelvin(unsigned long long int value) {
    return value - 273.15;
}

//end of the header guard section:
#endif
