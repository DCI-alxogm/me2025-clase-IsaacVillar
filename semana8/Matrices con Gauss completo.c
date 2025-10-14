#include<stdio.h>
#include<math.h>

#define FILAS_A 2  
#define COLS_A 3   

int main() {

    double A[FILAS_A][COLS_A] = {
        {1, 2, 10},
        {1.1, 2, 10.4} 
    };

    printf("Matriz original %dx%d:\n", FILAS_A, COLS_A);
    for (int i = 0; i < FILAS_A; i++) {
        for (int j = 0; j < COLS_A; j++) {
            printf("%8g ", A[i][j]);
        }
        printf("\n");
    }

    // En este paso se determina el número máximo de pasos de eliminación
    int max_pasos = (FILAS_A < COLS_A) ? FILAS_A - 1 : COLS_A - 1;
    
    for (int paso = 0; paso < max_pasos; paso++) {
        
        // Con pivote cero

if (fabs(A[paso][paso]) < 1e-10) {

    int fila_cambio = -1;
    for (int k = paso + 1; k < FILAS_A; k++) {
        if (fabs(A[k][paso]) > 1e-10) {
            fila_cambio = k;
            break;
        }
    }

    if (fila_cambio != -1) {
        for (int j = 0; j < COLS_A; j++) {
            double temp = A[paso][j];
            A[paso][j] = A[fila_cambio][j];
            A[fila_cambio][j] = temp;
        }
        printf("\nSe intercambió la fila %d con la fila %d para evitar pivote cero.\n", paso+1, fila_cambio+1);
    } else {
        printf("\nNo hay filas disponibles para intercambiar. No se puede continuar.\n");
      break;
    }

    for (int i = 0; i < FILAS_A; i++) {
        for (int j = 0; j < COLS_A; j++) {
            printf("%8g ", A[i][j]);
        }
        printf("\n");
    }
        }
        


        // Eliminar elementos debajo del pivote actual
        for (int i = paso + 1; i < FILAS_A; i++) {
            double factor = A[i][paso] / A[paso][paso];
            for (int j = paso; j < COLS_A; j++) {
                A[i][j] = A[i][j] - factor * A[paso][j];
            }
        }
        


        // Aquí imprimimos el paso en el que nos encontramos de eliminación
        printf("\nDespués del paso %d:\n", paso + 1);
        for (int i = 0; i < FILAS_A; i++) {
            for (int j = 0; j < COLS_A; j++) {
                printf("%8g ", A[i][j]);
            }
            printf("\n");
        }
    }

    printf("\nResultado con eliminación Gaussiana:\n");
    for (int i = 0; i < FILAS_A; i++) {
        for (int j = 0; j < COLS_A; j++) {
            printf("%8g ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}