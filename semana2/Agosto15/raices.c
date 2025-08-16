//David Isaac Oliva Villar
//Raices


#include<stdio.h>
#include<math.h>


int main() {
  float a,b,c,x1,x2,x1i,x2i,discr;
  int op;

printf("Introduzca el valor de las variables\n");
printf("a=");
scanf("%f", &a);
printf("\n");


printf("b=");
scanf("%f", &b);
printf("\n");


printf("c=");
scanf("%f", &c);
printf("\n");


if(a==0)
{
  if(b !=0){
  x1=-c/b;
  printf("x = %f\n", x1);
  }
  else{
  printf("la solución es trivial");
  printf("\n\n");
  }
}
else
  {
  discr = pow(b,2) - 4*(a*c);
  if(discr>0){
    x1=(-b+sqrt(discr))/(2*a);
    x2=(-b-sqrt(discr))/(2*a);


    printf("x1 = %f\n",x1);
    printf("x2 = %f\n",x2);
  }
  else{
    x1=-b/(2*a);
    x2=x1;
    x1i = sqrt(fabs(discr)) / (2*a);
    x2i=-x1i;


    printf("%f + %f i \n",x1,x1i);
    printf("%f + %f i \n",x2,x2i);
  }
}


printf("¿Volver a empezar?\n 1. Si\n 2. No");
printf("\n");
scanf("%d", &op);


    if (op == 1) {
        main(); // vuelve a llamar a main
    }

    return 0;

}
