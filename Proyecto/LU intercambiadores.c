// Método de factorización LU para 5 intercambiadores en serie
// David Isaac Oliva Villar

#include <stdio.h>

#define N 5

void imprimirMatriz(const char* nombre, double M[N][N]) {
    printf("\n%s:\n", nombre);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%10.2f ", M[i][j]);
        }
        printf("\n");
    }
}

void descomposicion_LU() {
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
        -5000*300 - 4000*600, // primera ecuación con T0
        -5000*300,
        -5000*300,
        -5000*300,
        -5000*300
    };

    double L[N][N] = {0};
    double U[N][N] = {0};
    double y[N], x[N];

    // Factorización LU (Doolittle)
    for (int i = 0; i < N; i++) {
        L[i][i] = 1;
        // U
        for (int j = i; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < i; k++) sum += L[i][k] * U[k][j];
            U[i][j] = A[i][j] - sum;
        }
        // L
        for (int j = i + 1; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < i; k++) sum += L[j][k] * U[k][i];
            L[j][i] = (A[j][i] - sum) / U[i][i];
        }
    }

    imprimirMatriz("Matriz L", L);
    imprimirMatriz("Matriz U", U);

    // Sustitución hacia adelante Ly = b
    for (int i = 0; i < N; i++) {
        double sum = 0.0;
        for (int j = 0; j < i; j++) sum += L[i][j] * y[j];
        y[i] = b[i] - sum;
    }

    // Sustitución hacia atrás Ux = y
    for (int i = N - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < N; j++) sum += U[i][j] * x[j];
        x[i] = (y[i] - sum) / U[i][i];
    }

    printf("\n--- Solución por Descomposición LU ---\n");
    for (int i = 0; i < N; i++) {
        printf("T[%d] = %.2f K\n", i+1, x[i]);
    }
}

int main() {
    descomposicion_LU();
    return 0;
}
