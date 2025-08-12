//David Isaac Oliva Villar
//Arreglo de 5 números enteros y funciones con ciclo if

#include<stdio.h>
#include<math.h>

int main() {
  int numeros[5];
  numeros [0]=1;
  numeros [1]=2;
  numeros [2]=3;
  numeros [3]=4;
  numeros [4]=5;

printf("Si es par, Logaritmo, si no, exponencial y coseno...\n\n");

  int indx;
  float resultados[5];
	for(indx=0; indx<5; indx++){
    if(numeros[indx]%2==0){
resultados[indx]=log10(numeros[indx]+1);
printf("x=%d\n log10(x+1)=%f\n",numeros[indx],resultados[indx]);}
	else{
    resultados[indx]=exp(numeros[indx])+cos(numeros[indx]);
	printf("x=%d\n exp(x)+cos(x)=%f\n",numeros[indx],resultados[indx]);}

  }
  }