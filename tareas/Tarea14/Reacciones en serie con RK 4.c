// Autor: David Isaac Oliva Villar
//Tema: Cinética Química - Reacciones en Serie (A -> B -> C)
//Método: Runge-Kutta 4to Orden para Sistemas

#include <stdio.h>

#define N 3 // Tenemos 3 especies: A, B, C

// Constantes de velocidad de reacción (unidades 1/min)
// k1: Velocidad de formación de B
// k2: Velocidad de degradación de B a C
const double K1 = 0.5;
const double K2 = 0.2;

// Función que define el sistema de ecuaciones diferenciales
// y[0] = Concentración de A
// y[1] = Concentración de B
// y[2] = Concentración de C
void cinetica_reaccion(double t, double y[], double f[]) {
    // d[A]/dt = -k1*[A]
    f[0] = -K1 * y[0];
    
    // d[B]/dt = k1*[A] - k2*[B]
    f[1] = (K1 * y[0]) - (K2 * y[1]);
    
    // d[C]/dt = k2*[B]
    f[2] = K2 * y[1];
}

int main() {
    // Configuración del tiempo (minutos)
    double t = 0.0;
    double t_final = 20.0; // Simulamos 20 minutos de reacción
    double h = 0.1;        // Paso de integración
    
    // Condiciones iniciales (Moles/Litro)
    // Empezamos solo con A puro.
    double y[N] = {1.0, 0.0, 0.0}; 
    
    // Variables auxiliares RK4
    double k1[N], k2[N], k3[N], k4[N];
    double y_temp[N]; 
    double f[N];      

    printf("--- SIMULACION REACTOR BATCH (A->B->C) ---\n");
    printf("Tiempo(min)\t[A]\t\t[B]\t\t[C]\n");
    printf("%.2f\t\t%.4f\t\t%.4f\t\t%.4f\n", t, y[0], y[1], y[2]);

    while (t < t_final) {
        
        // --- Paso 1 ---
        cinetica_reaccion(t, y, f);
        for(int i=0; i<N; i++) k1[i] = h * f[i];

        // --- Paso 2 ---
        for(int i=0; i<N; i++) y_temp[i] = y[i] + 0.5 * k1[i];
        cinetica_reaccion(t + 0.5*h, y_temp, f);
        for(int i=0; i<N; i++) k2[i] = h * f[i];

        // --- Paso 3 ---
        for(int i=0; i<N; i++) y_temp[i] = y[i] + 0.5 * k2[i];
        cinetica_reaccion(t + 0.5*h, y_temp, f);
        for(int i=0; i<N; i++) k3[i] = h * f[i];

        // --- Paso 4 ---
        for(int i=0; i<N; i++) y_temp[i] = y[i] + k3[i];
        cinetica_reaccion(t + h, y_temp, f);
        for(int i=0; i<N; i++) k4[i] = h * f[i];

        // --- Actualización de concentraciones ---
        for(int i=0; i<N; i++) {
            y[i] = y[i] + (1.0/6.0) * (k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
        }
        
        t = t + h;
        
        // Imprimimos los resultados
        printf("%.2f\t\t%.4f\t\t%.4f\t\t%.4f\n", t, y[0], y[1], y[2]);
    }

    return 0;
}