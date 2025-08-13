//David Isaac Oliva Villar
//Arreglo de 5 números flotantes y funciones con ciclo for

#include<stdio.h>
#include<math.h>

int main() {
  float a,b,c,d;
  a=3;
  b=4;
  c=5;
  d=7;

  float e;
  e =(a+b)*c/d;

  printf("Resultado 1:\n");
  printf("%f\n", e);

  e =((a+b)*c)/d;

  printf("Resultado 2:\n");
  printf("%f\n", e);

  e =a+(b*c)/d;

  printf("Resultado 3:\n");
  printf("%f\n", e);

  e =a+b*c/d;

  printf("Resultado 4:\n");
  printf("%f\n", e);
  }