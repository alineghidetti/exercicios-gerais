#include "temperature_conversor.h"
#include <stdio.h>

float convert_celsius_to_kelvin(float temperature){
    float kelvin;
    kelvin = temperature + 273.15;
    return kelvin;
}

float convert_celsius_to_fahrenheit(float temperature){
    float fahrenheit;
    fahrenheit = (temperature * 9.0/5) + 32;
    return fahrenheit;
}

float convert_kelvin_to_celsius(float temperature){
    float celsius;
    celsius = temperature - 273.15;
    return celsius;
}

float convert_kelvin_to_fahrenheit(float temperature){
    float fahrenheit;
    fahrenheit = ((temperature - 273.15) * 9.0/5) + 32;
    return fahrenheit;
}

float convert_fahrenheit_to_celsius(float temperature){
    float celsius;
    celsius = (temperature - 32) * (5.0/9);
    return celsius;
}

float convert_fahrenheit_to_kelvin(float temperature){
    float kelvin;
    kelvin = (temperature - 32) * (5.0/9) + 273.15;
    return kelvin;
}

float convert_temperature(float temperature, float convert_func(float temperature)){
    temperature = convert_func(temperature);
    return temperature;
}
