//David Isaac Oliva Villar
//Serie de Maclaurin para e^x
#include <stdio.h>
#include <math.h>

int main() {
    double x, Es, a_act, a_prev, exp; 
    int n;                
    int max_iter = 100;                 
    double term = 1.0;          
    double Ea = 100.0;                           
    int n_cumple = -1;          
  

    printf("Evaluacion de e^x por serie de Maclaurin con criterio de error\n");
    printf("Ingrese x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Entrada invalida para x.\n");
    }

    printf("Ingrese el error porcentual limite Es (por ejemplo 1 para 1%%): ");
    if (scanf("%lf", &Es) != 1 || Es <= 0.0) {
        printf("Entrada invalida para Es.\n");
    }

    printf("\n%-8s %-20s %-12s\n", "n", "Aprox e^x (S_n)", "Ea (%)");
    printf("------------------------------------------------------\n");

    a_prev = a_act;
    a_act += term; 
    Ea = 100.0; 
    printf("%-8d %-20.10f %-12s\n", n, a_act, "N/A");

    if (Ea <= Es) {
        n_cumple = n;
        exp = a_act;
    }

    for (n = 1; n < max_iter; n++) {
        term *= (x / n);

        a_prev = a_act;
        a_act += term; 

        Ea = fabs((a_act - a_prev) / a_act) * 100.0;

        printf("%-8d %-20.10f %-12.6f\n", n, a_act, Ea);

        if (Ea <= Es) {
            n_cumple = n;
            exp = a_act;
            break; //Aquí no recordaba el comando, pedí ayuda por que se iba de largo
        }
    }

    printf("------------------------------------------------------\n");
    if (n_cumple >= 0) {
        printf("Ea <= Es en n = %d\n", n_cumple);
        printf("Aprox final: e^x ≈ %.10f con Ea = %.6f %% (Es = %.6f %%)\n",
               exp, Ea, Es);
    } else {
        printf("No se alcanzo Ea <= Es en %d iteraciones. Ultima aprox: %.10f (Ea = %.6f %%)\n",
               max_iter, a_act, Ea);
    }
}
