//Método de factorización LU
//David Isaac Oliva Villar

#include <stdio.h>

#define N 3

void imprimirMatriz(const char* nombre, double M[N][N]) {
    printf("\n%s:\n", nombre);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%8.6f ", M[i][j]);
        }
        printf("\n");
    }
}

void descomposicion_LU() {
    // Matriz A
    double A[N][N] = {{3, -0.1, -0.2},
                      {0.1, 7, -0.3},
                      {0.3, -0.2, 10}};

    // Vector b
    double b[N] = {0, 0, 1};

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

    imprimirMatriz("Matriz L", L);
    imprimirMatriz("Matriz U", U);


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

    printf("\n--- Solucion por Descomposicion LU ---\n");
    printf("Vector Solucion x:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.6f\n", i, x[i]);
    }
}

int main() {
    descomposicion_LU();
return 0;
}