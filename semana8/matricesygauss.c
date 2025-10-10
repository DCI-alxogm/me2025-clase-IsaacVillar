#include<stdio.h>
#include<math.h>

#define FILAS_A 3
#define COLS_A 3

int main() {

int A[FILAS_A][COLS_A] = {
  {2,3,5},
  {4,9,13},
  {1,2,3}
};

    printf("A= \n");
    for (int i=0;i<FILAS_A;i++){
        for (int j= 0; j< COLS_A;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

int a=0;
    for (int i = a + 1; i < FILAS_A; i++) {
        double factor = A[i][a] / A[a][a];
                for (int j = a; j < COLS_A; j++) {
            A[i][j] = A[i][j] - factor * A[a][j];
        }
    }

    printf("\nA1= \n");
    for (int i=0;i<FILAS_A;i++){
        for (int j= 0; j< COLS_A;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }



int b=0;
    for (int i = b + 1; i < FILAS_A; i++) {
        double factor = A[i][b] / A[b][b];
                for (int j = b; j < COLS_A; j++) {
            A[i][j] = A[i][j] - factor * A[b][j];
        }
    }

    printf("\nA2= \n");
    for (int i=0;i<FILAS_A;i++){
        for (int j= 0; j< COLS_A;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}
