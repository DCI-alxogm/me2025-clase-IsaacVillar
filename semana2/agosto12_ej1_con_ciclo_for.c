//David Isaac Oliva Villar
//Arreglo de 5 números flotantes y funciones con ciclo for

#include<stdio.h>
#include<math.h>

int main() {
  float numeros[5];
  numeros [0]=1.1;
  numeros [1]=2.2;
  numeros [2]=3.3;
  numeros [3]=4.4;
  numeros [4]=5.5;

  printf("x\t x^2 \t log(x+1) \t exp(x)+cos(x)\n");

  int indx;
	for(indx=0; indx<5; indx++){
  printf("%.3f - %.3f - %.3f - %.3f\n", numeros[indx],numeros[indx]*numeros[indx], log10(numeros[indx]+1), exp(numeros[indx])+cos(numeros[indx]));
}
  }