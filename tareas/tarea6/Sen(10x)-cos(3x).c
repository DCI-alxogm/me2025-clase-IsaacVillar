//David Isaac Oliva Villar
//Optimización simple por bisección
#include <stdio.h>
#include <math.h>

int main() {
    double fa,fb,a,b,ea,es,k,fk,kn,eb,e,dif;
    int iter;                
    int max_iter = 100;                 
    double term = 1.0;
                                     

    printf("Evaluacion de f(x)=sen(10x)-cos(3x)\nEn un intervalo [a,b]\n");
    printf("\nIngrese a: \n");
    scanf("%lf", &a); 
    printf("Ingrese b: \n");
    scanf("%lf", &b);    

    iter = 1;
    ea = 1e9;

    printf("Ingrese el error limite Es (%%): ");
    scanf("%lf",&es);

    printf("\n%-6s %-10s %-10s %-16s %-16s %-12s %-10s %-10s\n", "iter","a", "b","f(a)", "f(b)", "Error (%)","Ea","Error c=Ea");
    printf("---------------------------------------------------------------------------------------------------------------\n");

    while (ea > es && iter < max_iter) {
    
    if(iter==1) {
      dif=fabs(b-a);
      eb=NAN;
      e=NAN;
    }



    e=dif/(pow(2,iter));

    k=(a+b)/2;

    fa=sin(10*a)-cos(3*a);
    fb=sin(10*b)-cos(3*b);

    fk=sin(10*k)-cos(3*k);


    ea=((fabs(k-kn))/k)*100;
    eb=fabs(k-kn);

    printf("%-6d %-10f %-10f %-16f %-16.10f %-12f %-10f %-10f \n",iter, a,b,fa, fb, ea,eb,e);
    

    if(fa*fk<0)
    b=k;
    else
    a=k;
    
    kn=k;

    iter++;

    }

}