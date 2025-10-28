//Método de factorización LU
//David Isaac Oliva Villar

#include <stdio.h>

#define N 3

void descomposicion_LU() {
    // Matriz A
    double A[N][N] = {{2, 1, 1},
                      {4, 3, 3},
                      {8, 7, 9}};

    // Vector b
    double b[N] = {5, 13, 31};

    // Matrices L y U
    double L[N][N] = {0};
    double U[N][N] = {0};
    double y[N];
    double x[N];

    for (int i = 0; i < N; i++) {
        L[i][i] = 1; 

        for (int j = i; j < N; j++) {
            // Calculo de U
            double sum = 0.0;
            for (int k = 0; k < i; k++) {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - sum;
        }

        for (int j = i + 1; j < N; j++) {
            // Calculo de L
            double sum = 0;
            for (int k = 0; k < i; k++) {
                sum += L[j][k] * U[k][i];
            }
            L[j][i] = (A[j][i] - sum) / U[i][i];
        }
    }

    for (int i = 0; i < N; i++) {
        double sum = 0.0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = b[i] - sum;
    }

    for (int i = N - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < N; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }

    printf("--- Solucion por Descomposicion LU ---\n");
    printf("Vector Solucion x:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.4f\n", i, x[i]);
    }
}

int main() {
    descomposicion_LU();
    return 0;
}