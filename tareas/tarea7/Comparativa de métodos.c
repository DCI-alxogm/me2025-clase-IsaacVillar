//David Isaac Oliva Villar
//Comparativo de métodos 
//Punto fijo, Newton-Raphson, secante y secante modificada

#include <stdio.h>
#include <math.h>

double f1(double x);
double df1(double x);
double d2f1(double x);

double f2(double x);
double df2(double x);
double d2f2(double x);

double f3(double x);
double df3(double x);
double d2f3(double x);

int main() {
    //ximen = x_i-1
    double xi, ximen,xiNR,xiPF,xiSEC,xism, rPF,rNR, rSEC,rsm,a;
    double fximen,fxiNR,fNR,gx,fSEC,ea,es,delta,dif=0.1;
    //derivadas
    int iter,opcion,metodo;                
    int max_iter = 100;                 
    double term = 1.0;
    double minimo = 1e-14;

    double (*d1)(double);
    double (*d2)(double);
    double(*f)(double);                                 

    printf("Raíces de e^-x -x\nCon un xi y xi-1\n");
    printf("(xi-1 es solo para N-R)\n(delta fijo para secante modificada de 0.1)\n");
    printf("¿Para que función trabajaremos?\n");
    printf("1). e^-x -x\n2). x^10-1\n3). x^3-5x^2-7x-3\n");
    scanf("%d", &opcion);
    printf("\n¿Qué método deseas emplear?\n");
    printf("1). Punto fijo\n2). Newton-Raphson\n3). N-R secante\n4). N-R secante modificado\n");
    scanf("%d", &metodo);
    printf("\nIngrese xi: \n");
    scanf("%lf", &xi); 
    printf("Ingrese xi-1 (solo relevante para método de la secante N-R): \n");
    scanf("%lf", &ximen);    

    iter = 0;
    ea = 1e9;

    printf("Ingrese el error limite Es (%%): ");
    scanf("%lf",&es);

    printf("\n%-6s %-10s %-10s\n", "iter","xi+1", "EA");
    printf("------------------------------\n");

    if (opcion == 1) {
    f  = f1;   d1 = df1;  d2 = d2f1;
    } else if (opcion == 2) {
    f  = f2;   d1 = df2;  d2 = d2f2;
    } else if (opcion == 3) {
    f  = f3;   d1 = df3;  d2 = d2f3;
    } else {
    printf("Opción de función no válida.\n");
    return 1;
    }

    xiNR=xi;
    xiPF=xi;
    xiSEC=xi;
    xism=xi;

    if(metodo == 1){
    //Punto fijo xi+1=g(x)
    while (ea > es && iter < max_iter) {
    
    if(opcion == 1){
      gx=exp(-xiPF);
    }
    else if (opcion == 2){
      gx=1;
    }
    else if (opcion == 3){
      gx= cbrt(5*pow(xiPF, 2) + 7*xiPF + 3);
    }

    rPF=gx;
    ea=((fabs(rPF-xiPF))/rPF)*100;
    printf("%-6d %-10f %-10f\n",iter, rPF, ea);
    xiPF=rPF;
    iter++;
    }
    }
    else if(metodo == 2){
    while (ea > es && iter < max_iter) {
    rNR = xiNR - f(xiNR)/d1(xiNR);

    if(fabs(d1(xiNR))<minimo){
      printf("El denominador es muy pequeño y diverge.\nNewton Raphson no funciona con xi = %.6f\n",xiNR);
      break;
    }

    ea=((fabs(rNR-xiNR))/rNR)*100;
    printf("%-6d %-10f %-10f\n",iter, rNR, ea);
    xiNR=rNR;
    iter++;
    }
    } else if(metodo == 3){
    while (ea > es && iter < max_iter) {
    delta=xiSEC-ximen;
    rSEC = xiSEC - (f(xiSEC)*(delta))/(f(xiSEC)-f(ximen));
    float denom=(f(xiSEC)-f(ximen));
    if(fabs(denom)<minimo){
      printf("El denominador es muy pequeño y diverge.\nN-R secante no funciona con xi = %.6f\n",xiSEC);
      break;
    }

    ea=((fabs(rSEC-xiSEC))/rSEC)*100;
    printf("%-6d %-10f %-10f\n",iter, rSEC, ea);
    ximen=xiSEC;
    xiSEC=rSEC;
    iter++;
    }      
    } else if(metodo == 4){
    while (ea > es && iter < max_iter) {
      a=xism+dif;
    rsm = xism - (f(xism)*(dif))/(f(a)-f(xism));

    ea=((fabs(rsm-xism))/rsm)*100;
    printf("%-6d %-10f %-10f\n",iter, rsm, ea);
    xism=rsm;
    iter++;
    }       
    }else {
    printf("Opción de método no válida.\n");
    return 1;
    }

    

}

// Funciones
double f1(double x) {
    return exp(-x)-x;
}
double df1(double x) {
  return -exp(-x)-1;
}
double d2f1(double x) { 
  return exp(-x);
}


double f2(double x) {
    return pow(x,10)-1;
}
double df2(double x) {
  return 10*pow(x,9);
}
double d2f2(double x) {
  return 90*pow(x,8);
}

double f3(double x) {
    return pow(x, 3) - 5*pow(x, 2) - 7*x - 3;
}
double df3(double x) {
    return 3*pow(x, 2) - 10*x - 7;
} 
double d2f3(double x) {
    return 6*x - 10;
}







