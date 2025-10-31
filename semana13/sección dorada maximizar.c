//David Isaac Oliva Villar
//Optimización simple por sección dorada (maximización)
#include <stdio.h>
#include <math.h>

int main() {
    double x1,x2,xl,xu,f1,f2,a,b, ea, es; 
    int iter;                
    int max_iter = 100;                 
    double term = 1.0;
                                     

    printf("Optimización simple por sección dorada (maximización)\n\n");
    printf("Ingrese xl: \n");
    scanf("%lf", &xl); 
    printf("Ingrese xu: \n");
    scanf("%lf", &xu);    

    iter = 0;
    ea = 1e9;

    printf("Ingrese el error limite Es: ");
    scanf("%lf",&es);

    printf("\n%-6s %-10s %-10s %-16s %-16s %-10s\n", "iter","x1", "x2","f(x1)", "f(x2)", "Error");
    printf("-------------------------------------------------------------------------\n");

    while (ea > es && iter < max_iter) {

    a=0.618*(xu-xl);
    b=(pow(0.618,2))*(xu-xl);

    x1=xl+a;
    x2=xl+b;

    f1=2*(sin(x1))-pow(x1,2)/10;
    f2=2*(sin(x2))-pow(x2,2)/10;

    ea=fabs(x2-x1);

    printf("%-6d %-10f %-10f %-16f %-16.10f %-10f\n",iter, x1,x2,f1, f2, ea);
    
    if(f1>f2)
    {
      xl=x2;
      }
      
    else
    {
      xu=x1;
    }
    iter++;
    }
}
