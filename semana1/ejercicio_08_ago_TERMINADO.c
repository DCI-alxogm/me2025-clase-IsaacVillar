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

//Operación x^2

  float cuad[5] = {pow(numeros[0], 2), pow(numeros[1],2), pow(numeros[2],2), pow(numeros[3],2), pow(numeros[4],2)};
  int size = sizeof(cuad) / sizeof(cuad[0]);
  int a;
  printf("Al cuadrado (x^2):\n");
  for (a = 0; a < size; a++) 
  {printf("%.3f ", cuad[a]);}
  printf("\n");

//Operación Log10(x+1)

  float loga[5] = {log10(numeros[0]+1), log10(numeros[1]+1), log10(numeros[2]+1), log10(numeros[3]+1), log10(numeros[4]+1)};
  int tam = sizeof(loga) / sizeof(loga[0]);
  int b;
  printf("Log_10(x+1):\n");
  for (b = 0; b < tam; b++) 
  {printf("%.3f ", loga[b]);}
  printf("\n");

//Operación exp(x)+cos(x)

  float ec[5] = {exp(numeros[0])+cos(numeros[0]), exp(numeros[1])+cos(numeros[1]), exp(numeros[2])+cos(numeros[2]), exp(numeros[3])+cos(numeros[3]), exp(numeros[4])+cos(numeros[4])};
  int t = sizeof(ec) / sizeof(ec[0]);
  int c;
  printf("exp(x)+cos(x) (Está en radianes):\n");
  for (c = 0; c < t; c++) 
  {printf("%.3f ", ec[c]);}
  printf("\n");

}