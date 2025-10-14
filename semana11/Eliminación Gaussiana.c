#include<stdio.h>
#include<math.h>

#define FILAS_A 4  
#define COLS_A 4   

int main() {

    double A[FILAS_A][COLS_A] = {
        {0, 3, 5,18},
        {4, 9, 13,40},
        {1, 2, 3,11},
        {7, 8, 10,48} 
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
        
        // Verificar que el pivote no sea cero
        if (fabs(A[paso][paso]) < 1e-10) {
            printf("\nPivote = 0, en la posición [%d][%d]. No se puede continuar.\n", paso+1, paso+1);
            break;
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