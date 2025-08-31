//David Isaac Oliva Villar
// Serie de Taylor para distintas funciones con criterio de error
// Usa xi como punto de expansión y muestra Error aproximado (Ea) y Error real (Er)

#include <stdio.h>
#include <math.h>

//Para no confundir antes de empezar:
//x = es xi+1 en la serie de Taylor, esto porque el valor x es al que se busca aproximar, pero no me dejaba declarar así a la variable  
//xi = es tal cual xi en la serie de Taylor, con esta no hubo problemas para declararla
int main() {
    int opcion, max_iter, n, n_cumple = -1;
    double x, xi, Es;
    double S = 0, S_prev = 0, term = 0, Ea = 100, Er = 0;
    double h, denom, sign, deriv, factor, realv = 0.0;

    printf("Elige funcion (Taylor alrededor de xi):\n");
    printf("1) e^x\n2) sin(x)\n3) cos(x)\n4) ln(x)\n5) 1/(1-x)\nOpcion: ");
    if (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 5) 
    { 
        printf("Entrada invalida.\n"); 
    }

    printf("Ingresa x (xi+1): "); 
    if (scanf("%lf", &x) != 1) 
    { 
        printf("Entrada invalida.\n"); 
    }
    printf("Ingresa xi (punto de expansion): "); 
    if (scanf("%lf", &xi) != 1) 
    { 
        printf("Entrada invalida.\n");  
    }
    printf("Ingresa Es (%%): "); 
    if (scanf("%lf", &Es) != 1 || Es <= 0.0) 
    {
        printf("Es invalido.\n"); 
    }
    printf("Maximo de iteraciones: "); 
    if (scanf("%d", &max_iter) != 1 || max_iter < 1) 
    { 
        printf("Iteraciones invalidas.\n"); 
    }

    // Revisiones de dominio
    if (opcion == 4 && (xi <= 0.0 || x <= 0.0)) 
    { 
        printf("Para ln(x) se requiere xi>0 y x>0.\n"); 
    }
    if (opcion == 5 && (x == 1.0 || xi == 1.0)) 
    { 
        printf("1/(1-x) es singular en x=1. Evita xi=1 y x=1.\n"); 
    }

    h = x - xi;

    printf("\n%-6s %-22s %-12s %-12s\n", "n", "S_n (aprox)", "Ea(%)", "Er(%)");
    printf("---------------------------------------------------------------\n");

    // Calcular el valor "real" con math.h
    if (opcion == 1) 
    realv = exp(x);
    else if (opcion == 2) 
    realv = sin(x);
    else if (opcion == 3) 
    realv = cos(x);
    else if (opcion == 4) 
    realv = log(x);
    else if (opcion == 5) 
    realv = 1/(1-x);

    // n = 0
    //term = epresenta el término individual que se está agregando en cada iteración
    //S = representa la suma acumulada de la serie hasta el término actual
    //factor = representa el término factorial y de potencia, funciona diferente al usado en un código pasado
    
    if (opcion == 1) 
    {
        S = exp(xi); term = S;
    } 
    else if (opcion == 2) 
    {
        factor = 1; deriv = sin(xi); 
        term = deriv * factor; S = term;
    } 
    else if (opcion == 3) 
    {
        factor = 1; deriv = cos(xi); 
        term = deriv * factor; S = term;
    } 
    else if (opcion == 4) 
    {
        S = log(xi);
    } 
    else if (opcion == 5) 
    {
        denom = 1 - xi; S = 1/denom;
    }

    Er = fabs((realv - S) / realv) * 100.0;
    
    //Primera línea donde n=0
    printf("%-6d %-22.12f %-12s %-12.8f\n", 0, S, "N/A", Er);

    // Iteraciones
    for (n = 1; n < max_iter; ++n) 
    {
        if (opcion == 1) //exponencial
        {
            term *= h / n;
            S_prev = S; S += term;
        } 
        else if (opcion == 2) //Coseno
        {
            factor *= h / n;
            if      (n % 4 == 0) deriv = sin(xi);
            else if (n % 4 == 1) deriv = cos(xi);
            else if (n % 4 == 2) deriv = -sin(xi);
            else                  deriv = -cos(xi);
            S_prev = S; S += deriv * factor;
        } 
        else if (opcion == 3) //Seno
        {
            factor *= h / n;
            if      (n % 4 == 0) deriv = cos(xi);
            else if (n % 4 == 1) deriv = -sin(xi);
            else if (n % 4 == 2) deriv = -cos(xi);
            else                  deriv =  sin(xi);
            S_prev = S; S += deriv * factor;
        } 
        else if (opcion == 4) //logaritmo natural
        {
            sign = (n % 2) ? 1 : -1;
            term = sign * pow(h, n) / ( (double)n * pow(xi, n) );
            S_prev = S; S += term;
        } 
        else if (opcion == 5) //1/1-x
        {
            term = pow(h, n) / pow(1 - xi, n + 1);
            S_prev = S; S += term;
        }

        Ea = fabs((S - S_prev) / S) * 100;
        Er = fabs((realv - S) / realv) * 100;
        printf("%-6d %-22.12f %-12.8f %-12.8f\n", n, S, Ea, Er);

        //Aquí termina el ciclo, pero agregamos lo de abajo para que también indique en que término de la serie se llega al Error ingresado
        if (Ea <= Es) { n_cumple = n; break; }
    }

    printf("---------------------------------------------------------------\n");
    if (n_cumple >= 0) {
        printf("Ea <= Es en n = %d\n", n_cumple);
        printf("Aprox final: %.12f con Ea = %.8f %% | Er = %.8f %%\n", S, Ea, Er);
    } else {
        printf("No se alcanzo Ea <= Es en %d iteraciones. Ultima aprox: %.12f (Ea = %.8f %%)\n",
               max_iter, S, Ea);
    }
    printf("Valor real: %.12f\n", realv);
}
