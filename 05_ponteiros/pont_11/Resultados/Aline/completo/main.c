#include "calculadora.h"
#include <stdio.h>

float a (float a, float b) {
    return a + b;
}
float s (float a, float b) {
    return a - b;
}
float m (float a, float b) {
    return a * b;
}
float d (float a, float b) {
    return a / b;
}
int main(){
    char op;
    float n1, n2, res;
    while(1){
        scanf("%c%*c", &op);
        if(op == 'f'){
            break;
        }
        else if(op == 'a'){
            scanf("%f %f\n", &n1, &n2);
            res = Calcular(n1, n2, a);
            printf("%.2f + %.2f = %.2f\n", n1, n2, res);
        }
        else if(op == 's'){
            scanf("%f %f\n", &n1, &n2);
            res = Calcular(n1, n2, s);
            printf("%.2f - %.2f = %.2f\n", n1, n2, res);
        }
        else if(op == 'm'){
            scanf("%f %f\n", &n1, &n2);
            res = Calcular(n1, n2, m);
            printf("%.2f x %.2f = %.2f\n", n1, n2, res);
        }
        else if(op == 'd'){
            scanf("%f %f\n", &n1, &n2);
            res = Calcular(n1, n2, d);
            printf("%.2f / %.2f = %.2f\n", n1, n2, res);
        }
    }
}