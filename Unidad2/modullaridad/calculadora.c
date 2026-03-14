#include <stdio.h>
#include "areas.h"
#include "volumenes.h"

#define PI 3.14159265

// Implementación de funciones de áreas
float area_circulo(float radio) {
    return PI * radio * radio;
}

float area_cuadrado(float lado) {
    return lado * lado;
}

// Implementación de funciones de volúmenes
float volumen_esfera(float radio) {
    return (4.0/3.0) * PI * radio * radio * radio;
}

float volumen_cubo(float lado) {
    return lado * lado * lado;
}

// Función principal
int main() {
    float radio_ejemplo = 5.0;
    float lado_ejemplo = 4.0;

    printf("=== CALCULADORA DE GEOMETRÍA ===\n");
    printf("Área de círculo (radio %.2f): %.2f\n", radio_ejemplo, area_circulo(radio_ejemplo));
    printf("Área de cuadrado (lado %.2f): %.2f\n", lado_ejemplo, area_cuadrado(lado_ejemplo));
    printf("Volumen de esfera (radio %.2f): %.2f\n", radio_ejemplo, volumen_esfera(radio_ejemplo));
    printf("Volumen de cubo (lado %.2f): %.2f\n", lado_ejemplo, volumen_cubo(lado_ejemplo));

    return 0;
}
