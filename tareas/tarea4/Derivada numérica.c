//David Isaac Oliva Villar
//Derivadas numéricas

#include <stdio.h>
#include <math.h>

int main() {
    double xi,xa,xb,fx,fa,fb,da,db,dc,ea,eb,ec;
    double h1, h2, h3;
    double er;                                       

    printf("Derivadas numéricas\n");
    printf("Ingrese xi: \n");
    scanf("%lf", &xi); 
    printf("Ingrese xi+1: \n");
    scanf("%lf", &xb);    
    printf("Ingrese xi-1: \n");
    scanf("%lf", &xa);    
    
    printf("Ingrese f(xi): \n");
    scanf("%lf", &fx); 
    printf("Ingrese f(xi+1): \n");
    scanf("%lf", &fb); 
    printf("Ingrese f(xi-1): \n");
    scanf("%lf", &fa); 

    printf("Ingrese el valor real de f'(xi): \n");
    scanf("%lf", &er); 

    h1=xb-xi;
    h2=xi-xa;
    h3=xb-xa;

    da=((fx-fa)/h2);
    db=((fb-fx)/h1);
    dc=((fb-fa)/h3);

    ea=((fabs(er-da))/er)*100;
    eb=((fabs(er-db))/er)*100;
    ec=((fabs(er-dc))/er)*100;

    printf("\n%-10s %-16s %-16s %-16s %-15s %-15s %-15s\n", "x", "f'(xi) delante", "f'(xi) detrás", "f'(xi) Centrada", "Error delante", "Error detrás", "Error centrada");
    printf("---------------------------------------------------------------------------------------------------------\n");

    printf("%-10.3f %-16.5f %-16.5f %-16.5f %-15.3f %-15.3f %-15.3f\n", xi, db,da,dc,eb,ea,ec);
    
  
    }

