//David Isaac Oliva Villar
//MÉTODO DE ASCENSO POR GRADIENTE USANDO DIFERENCIAS FINITAS PARA DERIVADAS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double H = 1e-6;          // Paso para diferencias finitas
const double ALFA = 0.01;       // Tasa de aprendizaje
const double TOLERANCIA = 1e-7; // Convergencia según magnitud del gradiente
const int MAX_ITER = 100000;    // Máximo de iteraciones

//Función a maximizar
double f(double x, double y) {
    return 10.0 - pow(x - 2.0, 2) - pow(y - 3.0, 2);
    // Ejemplo alternativo: return sin(x) * cos(y);
}

//Calculamos el gradiente usando diferencias finitas centrales.
void calcular_gradiente(double x, double y, double *grad_x, double *grad_y) {
    *grad_x = (f(x + H, y) - f(x - H, y)) / (2.0 * H);
    *grad_y = (f(x, y + H) - f(x, y - H)) / (2.0 * H);
}

int main() {
    double x = 0.0; // Punto inicial
    double y = 0.0;

    double grad_x, grad_y;
    int iter;

    for (iter = 0; iter < MAX_ITER; iter++) {
        // Calcular gradiente en el punto actual
        calcular_gradiente(x, y, &grad_x, &grad_y);

        // Magnitud del gradiente
        double magnitud = sqrt(grad_x*grad_x + grad_y*grad_y);

        // Verificar convergencia
        if (magnitud < TOLERANCIA) {
            break;
        }

        // Actualizar coordenadas (ascenso por gradiente)
        x += ALFA * grad_x;
        y += ALFA * grad_y;
    }

    // Resultados finales
    printf("Máximo local encontrado en:\n");
    printf("x = %.8f\n", x);
    printf("y = %.8f\n", y);
    printf("Valor de f(x,y) = %.8f\n", f(x, y));

    if (iter == MAX_ITER) {
        printf("Se alcanzó el máximo de iteraciones sin converger.\n");
    } else {
        printf("Convergencia alcanzada en iteración %d\n", iter);
    }

    return EXIT_SUCCESS;
}
