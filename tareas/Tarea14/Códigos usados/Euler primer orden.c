//Autor: David Isaac Oliva Villar
//Método: Euler (Primer Orden)


#include <stdio.h>

// Definimos la función f(x, y) = dy/dx
double f(double x, double y) {
    return x + y; // Ejemplo: dy/dx = x + y
}

int main() {
    double x0 = 0.0, y0 = 1.0; // Condiciones iniciales
    double x_final = 1.0;      // Hasta dónde queremos calcular
    double h = 0.1;            // Tamaño de paso
    double x = x0, y = y0;

    printf("--- METODO DE EULER ---\n");
    printf("x\t\ty\n");
    printf("%.6f\t%.6f\n", x, y);

    while (x < x_final) {
        y = y + h * f(x, y); // Fórmula de Euler
        x = x + h;
        
        printf("%.6f\t%.6f\n", x, y);
    }

    return 0;
}