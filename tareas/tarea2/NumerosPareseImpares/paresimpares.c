//David Isaac Oliva Villar
//Raices


#include<stdio.h>
#include<math.h>


int main() {

int n,op;
printf("Digite un número entero: \n");
scanf("%d",&n);
printf("\n");

if (n%2 == 0){
  printf("El número %d es par",n);
  printf("\n");

}
else{
  printf("El número %d es impar",n);
  printf("\n");
}

printf("¿Volver a empezar?\n 1. Si\n 2. No");
printf("\n");
scanf("%d", &op);


    if (op == 1) {
        main();
    }

}

