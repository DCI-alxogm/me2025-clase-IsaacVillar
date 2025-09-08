//David Isaac Oliva Villar
//Derivadas gg ff
#include <stdio.h>
#include <math.h>

float fx(float x);

int main() {
    float a,b,h;
    int n,i; 
    a=-2;
    b=2;
    h=0.25;
    n=(int)((b-a)/h);
    float x[n], fp[n],fpp[n],fpa[n], fpb[n], fpc[n], fppa[n], fppb[n], fppc[n]; 

printf("Derivadas primera y segunda de x^3-2x+4\n");
printf("-----------------------------------------");
printf("\n%-9s | %-9s | %-9s | %-9s | %-9s | %-9s | %-9s | %-9s | %-9s |\n", "x", "f'(xi)", "f'(xi)+", "f'(xi)-", "f'(xi) c", "f''(xi)","f''(xi)+","f''(xi)-","f''(xi)c");
printf("-----------------------------------------------------------------------------------------------------------\n");
    
    for (i=0; i<=n; i++)
    {
    x[i]=a + (i*h);

    fp[i]=(3*(pow(x[i],2)))-2;
    fpp[i]= 6*(x[i]);

    if (i < n)
    //No entiendo por qué, pero solo me funcionó poniendo así la derivada adelante 
    fpa[i] = (fx(a +(i+1)*h)-fx(a+(i*h)))/h;    
    else
    fpa[i] = NAN;

    if (i < n-1)
    fppa[i] = (fx(a +(i)*h) - 2*(fx(a +(i+1)*h)) + fx(a +(i+2)*h))/(pow(h,2));
    else
    fppa[i] = NAN;


    if (i > 0)
    fpb[i] = (fx(x[i]) - fx(x[i-1])) / h;
    else
    fpb[i] = NAN;

    if (i > 1)
    fppb[i] = (fx(a +(i-2)*h) - 2*(fx(a +(i-1)*h)) + fx(a +(i)*h))/(pow(h,2));
    else
    fppb[i] = NAN;

    if (i > 0 && i < n)
    //Con la centrada fue el mismo caso
    //Solo haciéndolo más explícito me funcionó bien
    fpc[i] = (fx(a +(i+1)*h) - fx(a +(i-1)*h)) / (2*h);
    else
    fpc[i] = NAN;
    

    if (i > 0 && i < n)
    fppc[i] = (fx(a +(i+1)*h) - 2*(fx(a +(i)*h)) + fx(a +(i-1)*h))/(pow(h,2));
    else
    fppc[i] = NAN;

    printf("%-9.4f | %-9.4f| %-9.4f | %-9.4f | %-9.4f | %-9.4f | %-9.4f | %-9.4f | %-9.4f  |\n",x[i],fp[i],fpa[i],fpb[i],fpc[i],fpp[i],fppa[i],fppb[i],fppc[i]);
    
    
    }                           
    
}

float fx(float x)
{
float f;
f=(pow(x,3))-(2*x)+4;
return f;
}
