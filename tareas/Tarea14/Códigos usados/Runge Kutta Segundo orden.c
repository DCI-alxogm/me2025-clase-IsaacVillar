//Autor: David Isaac Oliva Villar
//Método: Runge-Kutta 2do Orden (Método de Heun)

#include <stdio.h>

double f(double x, double y) {
    return x + y; 
}

int main() {
    double x0 = 0.0, y0 = 1.0;
    double x_final = 1.0;
    double h = 0.1;
    double x = x0, y = y0;
    double k1, k2;

    printf("--- METODO DE RK2 (HEUN) ---\n");
    printf("x\t\ty\n");
    printf("%.6f\t%.6f\n", x, y);

    while (x < x_final) {
        k1 = f(x, y);
        k2 = f(x + h, y + h * k1);
        
        // Promedio de pendientes
        y = y + (h / 2.0) * (k1 + k2);
        x = x + h;

        printf("%.6f\t%.6f\n", x, y);
    }

    return 0;
}