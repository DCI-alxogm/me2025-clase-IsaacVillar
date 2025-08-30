#include<stdio.h>
#include<math.h>

int main (){

double xa,xb,h,m,r1,fv,fa;
printf("Función f(x)=x^m, con aproximación de primer orden\n");
printf("Introduzca xi\n");
scanf("%lf", &xa);

printf("Introduzca xi+1\n");
scanf("%lf",&xb);

h=xb-xa;

printf("Introduzca el exponente m\n");
scanf("%lf",&m);

fv=pow(xb,m);
fa=pow(xa,m)+(m*(pow(xa,m-1))*h);
r1=((m*(m-1)*pow(xa,m-2)*pow(h,2))/2)+((m*(m-1)*(m-2)*(pow(xa,m-3))*(pow(h,3)))/6);

printf("f(x) real = %lf\n", fv);
printf("f(x) aprox = %lf\n",fa);
printf("R1 = %lf",r1);
}