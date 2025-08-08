//David Isaac Oliva Villar
//Arreglo de 5 números flotantes y funciones

#include<stdio.h>
#include<math.h>

int main() {
  float numeros[5] = {1.25, 3.41, 5.66, 7.88, 9.071};
  int tamano = sizeof(numeros) / sizeof(numeros[0]);
  int i;

  printf("Arreglo:\n");
  for (i = 0; i < tamano; i++) 
  {printf("%.3f ", numeros[i]);}
  printf("\n");

  float cuad[5] = {pow(numeros[0], 2), pow(numeros[1],2), pow(numeros[2],2), pow(numeros[3],2), pow(numeros[4],2)};
  int size = sizeof(cuad) / sizeof(cuad[0]);
  int a;
  printf("Al cuadrado:\n");
  for (a = 0; a < tamano; a++) 
  {printf("%.3f ", cuad[a]);}
  printf("\n");
}