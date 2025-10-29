#include<stdio.h>
#include<math.h>

#define FILAS_A 4  
#define COLS_A 4   

int main() {

    double A[FILAS_A][COLS_A] = {
        {0, 3, 5, 21},
        {4, 9, 13, 61},
        {1, 2, 3, 14},
        {7, 8, 10, 53} 
    };

    printf("Matriz original %dx%d:\n", FILAS_A, COLS_A);
    for (int i = 0; i < FILAS_A; i++) {
        for (int j = 0; j < COLS_A; j++) {
            printf("%10.4f ", A[i][j]);
        }
        printf("\n");
    }
  
    int n_incognitas = COLS_A - 1;
    int n_pasos = (FILAS_A < n_incognitas) ? FILAS_A : n_incognitas;
    
    for (int paso = 0; paso < n_pasos; paso++) {
        
        int max_fila = paso;
        for (int i = paso + 1; i < FILAS_A; i++) {
            if (fabs(A[i][paso]) > fabs(A[max_fila][paso])) {
                max_fila = i;
            }
        }
        
        if (max_fila != paso) {
            for (int j = 0; j < COLS_A; j++) {
                double temp = A[paso][j];
                A[paso][j] = A[max_fila][j];
                A[max_fila][j] = temp;
            }
        }

        // Verificacion de que el pivote no sea cero
        if (fabs(A[paso][paso]) < 1e-10) {
            printf("\nPivote = 0, en la posición [%d][%d]. El sistema no tiene solución única.\n", paso+1, paso+1);
            return 1; 
        }
        

        double pivote = A[paso][paso];
        for (int j = paso; j < COLS_A; j++) {
            A[paso][j] = A[paso][j] / pivote;
        }


        for (int i = 0; i < FILAS_A; i++) {
            if (i != paso) {
                double factor = A[i][paso]; 
                for (int j = paso; j < COLS_A; j++) {
                    A[i][j] = A[i][j] - factor * A[paso][j];
                }
            }
        }

        printf("\nDespués del paso %d (Pivote en [%d][%d]):\n", paso + 1, paso+1, paso+1);
        for (int i = 0; i < FILAS_A; i++) {
            for (int j = 0; j < COLS_A; j++) {
                printf("%10.4f ", A[i][j]);
            }
            printf("\n");
        }
    }

    printf("Matriz en forma escalonada (Gauss-Jordan):\n");
    for (int i = 0; i < FILAS_A; i++) {
        for (int j = 0; j < COLS_A; j++) {
            printf("%10.4f ", A[i][j]);
        }
        printf("\n");
    }
    
    printf("\nSolucion:\n");
    for (int i = 0; i < n_pasos; i++) {
        printf("x%d = %10.4f\n", i+1, A[i][COLS_A - 1]);
    }
    
    for (int i = n_pasos; i < FILAS_A; i++) {
        if (fabs(A[i][COLS_A - 1]) > 1e-10) {
            printf("\nAdvertencia: El sistema es inconsistente (fila %d no es cero).\n", i+1);
        }
    }


    return 0;
}
