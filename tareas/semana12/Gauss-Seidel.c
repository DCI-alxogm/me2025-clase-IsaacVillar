//Gauss-Seidel
//Autor: David Isaac Oliva Villar
#include <stdio.h>
#include <math.h>

#define N 3

void gauss_seidel() {
    // Matriz A
    double A[N][N] = {{10, -1, 2},
                      {-1, 11, -1},
                      {2, -1, 10}};

    // Vector b
    double b[N] = {6, 25, -11};

    double x[N] = {0, 0, 0}; // Aproximación inicial (x^k+1)
    double x_old[N];               // x^k

    double error_max = 0.0001; // Tolerancia de error
    int max_iter = 50;         // Máximo de iteraciones
    int iter = 0;

    printf("--- Solucion por Gauss-Seidel ---\n");

    while (iter < max_iter) {
        for (int i = 0; i < N; i++) {
            x_old[i] = x[i];
        }

        for (int i = 0; i < N; i++) {
            double sum = 0.0;
            for (int j = 0; j < N; j++) {
                if (i != j) {

                    sum += A[i][j] * x[j]; 
                }
            }
            // Formula de Gauss-Seidel: x_i^(k+1) = (b_i - sum) / a_ii
            x[i] = (b[i] - sum) / A[i][i];
        }
        double error_actual = 0;
        for (int i = 0; i < N; i++) {
            double diff = fabs(x[i] - x_old[i]);
            if (diff > error_actual) {
                error_actual = diff;
            }
        }

        iter++;

        if (error_actual < error_max) {
            break;
        }
    }

    printf("Iteraciones: %d\n", iter);
    printf("Vector Solucion x:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.4f\n", i, x[i]);
    }
}

int main() {
     gauss_seidel();
     return 0;
 }