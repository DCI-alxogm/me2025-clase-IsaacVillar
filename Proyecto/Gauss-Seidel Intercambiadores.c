// Gauss-Seidel para 5 intercambiadores de calor en serie
// David Isaac Oliva Villar

#include <stdio.h>
#include <math.h>

#define N 5

void gauss_seidel() {
    // Matriz A (coeficientes de T1..T5)
    double A[N][N] = {
        {-9000,    0,     0,     0,     0},
        { 4000, -9000,    0,     0,     0},
        {   0,  4000, -9000,    0,     0},
        {   0,    0,  4000, -9000,    0},
        {   0,    0,    0,  4000, -9000}
    };

    // Vector b (lado derecho del sistema)
    double b[N] = {
        -5000*300 - 4000*600,  // Primera ecuación con T0
        -5000*300,
        -5000*300,
        -5000*300,
        -5000*300
    };

    double x[N] = {0, 0, 0, 0, 0};  // Aproximación inicial
    double x_old[N];
    double tol = 1e-4;
    int max_iter = 100;
    int iter = 0;

    while (iter < max_iter) {
        for (int i = 0; i < N; i++) x_old[i] = x[i];

        for (int i = 0; i < N; i++) {
            double sum = 0.0;
            for (int j = 0; j < N; j++) {
                if (i != j) sum += A[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        // Calcular error máximo
        double error_max = 0.0;
        for (int i = 0; i < N; i++) {
            double diff = fabs(x[i] - x_old[i]);
            if (diff > error_max) error_max = diff;
        }

        iter++;
        if (error_max < tol) break;
    }

    printf("--- Solución por Gauss-Seidel ---\n");
    printf("Iteraciones: %d\n", iter);
    for (int i = 0; i < N; i++) {
        printf("T[%d] = %.2f K\n", i+1, x[i]);
    }
}

int main() {
    gauss_seidel();
    return 0;
}
