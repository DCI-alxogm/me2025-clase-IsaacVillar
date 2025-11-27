//Autor: David Isaac Oliva Villar
 //Método: Runge-Kutta 4to Orden (RK4)

#include <stdio.h>

double f(double x, double y) {
    return x + y; 
}

int main() {
    double x0 = 0.0, y0 = 1.0;
    double x_final = 1.0;
    double h = 0.1;
    double x = x0, y = y0;
    double k1, k2, k3, k4;

    printf("--- METODO DE RK4 ---\n");
    printf("x\t\ty\n");
    printf("%.6f\t%.6f\n", x, y);

    while (x < x_final) {
        k1 = h * f(x, y);
        k2 = h * f(x + 0.5 * h, y + 0.5 * k1);
        k3 = h * f(x + 0.5 * h, y + 0.5 * k2);
        k4 = h * f(x + h, y + k3);

        // Promedio ponderado (1:2:2:1)
        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x = x + h;

        printf("%.6f\t%.6f\n", x, y);
    }

    return 0;
}