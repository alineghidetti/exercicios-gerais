#include <stdio.h>
#include "temperature_conversor.h"

int main(){
    float temp, convert;
    char unit_old, unit_new;
    scanf("%f %c %c", &temp, &unit_old, &unit_new);

    if(unit_old == 'c'){
        if(unit_new == 'f'){
            convert = convert_temperature(temp, convert_celsius_to_fahrenheit);
        }
        else if(unit_new == 'k'){
            convert = convert_temperature(temp, convert_celsius_to_kelvin);
        }
    }
    else if(unit_old == 'f'){
        if(unit_new == 'c'){
            convert = convert_temperature(temp, convert_fahrenheit_to_celsius);
        }
        else if(unit_new == 'k'){
            convert = convert_temperature(temp, convert_fahrenheit_to_kelvin);
        }
    }
    else if(unit_old == 'k'){
        if(unit_new == 'c'){
            convert =  convert_temperature(temp, convert_kelvin_to_celsius);
        }
        else if(unit_new == 'f'){
            convert = convert_temperature(temp, convert_kelvin_to_fahrenheit);
        }
    }

    printf("Temperature: %.2f%c", convert, unit_new-32);
    if(unit_new == 'c' || unit_new == 'f'){
        printf("º");
    }
    
    return 0;
}