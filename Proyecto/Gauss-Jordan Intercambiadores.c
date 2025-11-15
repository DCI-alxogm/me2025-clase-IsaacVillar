#include<stdio.h>
#include<math.h>

#define N 5   // Número de incógnitas

int main() {
    // Matriz aumentada [A|b]
    double A[N][N+1] = {
        {-9000,    0,     0,     0,     0,  -5000*300 - 4000*600},  // T1
        { 4000, -9000,    0,     0,     0,  -5000*300},             // T2
        {   0,  4000, -9000,    0,     0,  -5000*300},             // T3
        {   0,    0,  4000, -9000,    0,  -5000*300},             // T4
        {   0,    0,    0,  4000, -9000,  -5000*300}              // T5
    };

    for (int paso = 0; paso < N; paso++) {
        // Intercambio de filas para pivotaje parcial
        int max_fila = paso;
        for (int i = paso + 1; i < N; i++) {
            if (fabs(A[i][paso]) > fabs(A[max_fila][paso])) {
                max_fila = i;
            }
        }
        if (max_fila != paso) {
            for (int j = 0; j < N+1; j++) {
                double temp = A[paso][j];
                A[paso][j] = A[max_fila][j];
                A[max_fila][j] = temp;
            }
        }

        // Verificación de pivote
        if (fabs(A[paso][paso]) < 1e-10) {
            printf("Pivote cero en fila %d\n", paso+1);
            return 1;
        }

        // Normalizar fila del pivote
        double pivote = A[paso][paso];
        for (int j = paso; j < N+1; j++) {
            A[paso][j] /= pivote;
        }

        // Eliminar otras filas
        for (int i = 0; i < N; i++) {
            if (i != paso) {
                double factor = A[i][paso];
                for (int j = paso; j < N+1; j++) {
                    A[i][j] -= factor * A[paso][j];
                }
            }
        }
    }

    // Mostrar solución
    printf("--- Solución por Gauss-Jordan ---\n");
    for (int i = 0; i < N; i++) {
        printf("T[%d] = %.2f K\n", i+1, A[i][N]);
    }

    return 0;
}
