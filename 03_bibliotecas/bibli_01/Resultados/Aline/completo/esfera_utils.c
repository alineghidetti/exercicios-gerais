#include "esfera_utils.h"

float calcula_volume(float R){
    float volume;
    volume = (4*PI*R*R*R)/3;
    return volume;
}

float calcula_area(float R){
    float area;
    area = 4*PI*R*R;
    return area;
}
