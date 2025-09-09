//David Isaac Oliva Villar
//Optimización simple por bisección
#include <stdio.h>
#include <math.h>

int main() {
    double fa,fb,a,b,ea,es,k,fk,kn;
    double g=9.81,m=68.1,v=40,t=10;
    int iter;                
    int max_iter = 100;                 
    double term = 1.0;
                                     

    printf("Evaluacion de f(c)=(gm/c)(1-exp(-ct/m))-v\nEn un intervalo [a,b]\n");
    printf("\nIngrese a: \n");
    scanf("%lf", &a); 
    printf("Ingrese b: \n");
    scanf("%lf", &b);    

    iter = 0;
    ea = 1e9;

    printf("Ingrese el error limite Es (%%): ");
    scanf("%lf",&es);

    printf("\n%-6s %-10s %-10s %-16s %-16s %-10s\n", "iter","a", "b","f(a)", "f(b)", "Error (%%)");
    printf("-------------------------------------------------------------------------\n");

    while (ea > es && iter < max_iter) {

    k=(a+b)/2;

    fa=(g*m/a)*(1-exp(-a*t/m))-v;
    fb=(g*m/b)*(1-exp(-b*t/m))-v;

    fk=(g*m/k)*(1-exp(-k*t/m))-v;


    ea=((fabs(k-kn))/k)*100;

    printf("%-6d %-10f %-10f %-16f %-16.10f %-10f\n",iter, a,b,fa, fb, ea);
    

    if(fa*fk<0)
    b=k;
    else
    a=k;
    
    kn=k;

    iter++;
    }

}
