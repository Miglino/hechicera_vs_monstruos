#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void cargarVectores(int*, int*, char*, int, int, char, int);
void calcularGanador (int*, int*, char*, int);

int main () {
	
	int opcionMenu, monstruoHechicera, monstruoRival;
	int a, i = 0;
	int validarOpcion = 0;
	int vecHechicera[50], vecRival[50];
	char vecGanador[50];
	char monstruoGanador;
	
	for(a=0; a<50; a++) {
		vecHechicera[a] = 0;
	}
	for(a=0; a<50; a++) {
		vecRival[a] = 0;
	}
	for(a=0; a<50; a++) {
		vecGanador[a] = 'z';
	}	
	
      while (validarOpcion == 0) {
          

           
           if (opcionMenu != 3 && opcionMenu != 0 && opcionMenu <=3) {
          
              validarOpcion = 1;
          
            	switch(opcionMenu) {
            			case 1:
            				printf("Nivel de poder del monstruo de la hechicera: \n");
            				fflush(stdin);
            				scanf("%d", &monstruoHechicera);
            				printf("Nivel de poder del monstruo rival: \n");
            				fflush(stdin);
            				scanf("%d", &monstruoRival);
            				system("cls");
            
            				if(monstruoHechicera>monstruoRival || monstruoHechicera==monstruoRival) {
            					printf("El ganador es el monstruo de la hechicera\n");
            					monstruoGanador = 'h';
            					system("pause");
            					system("cls");
            				} else if (monstruoHechicera<monstruoRival) {
            					printf("El ganador es el monstruo del rival\n");
            					monstruoGanador = 'r';
            					system("pause");
            					system("cls");
            				}
            				
            				cargarVectores(vecHechicera, vecRival, vecGanador, monstruoHechicera, monstruoRival, monstruoGanador, i);
            				i++;
            			break;
            			case 2:
            				calcularGanador(vecHechicera, vecRival, vecGanador, i);	
            				system("pause");
            				system("cls");
            			break;			
      }
	
    }
		
  }	       
  	     
}

void cargarVectores (int* vecHechicera, int* vecRival, char* vecGanador, int monstruoHechicera, int monstruoRival, char monstruoGanador, int x) {
	
	*(vecHechicera + x) = monstruoHechicera;
	*(vecRival + x) = monstruoRival;
	*(vecGanador + x) = monstruoGanador;
}

void calcularGanador (int* vecHechicera, int* vecRival, char* vecGanador, int i) {
	
	int p; 
	static int cantidadH = 0;
	static int cantidadR = 0;
	static int acumHechicera = 0;
	static int acumRival = 0;
	float promedioHechicera , promedioRival;
	int poderMaxHechicera = *vecHechicera;
	int poderMaxRival = *vecRival;
	
	
	
	for(p=0; p<i; p++) {
		if(*(vecGanador + p) == 'h'){
			cantidadH = cantidadH +1;
			acumHechicera = acumHechicera + *(vecHechicera + p);
			promedioHechicera = acumHechicera / cantidadH;
			
		}else if(*(vecGanador + p) == 'r'){
			cantidadR = cantidadR +1;
			acumRival = acumRival + *(vecRival + p);
			promedioRival = acumRival / cantidadR;
		}
		if(*(vecHechicera + p) > poderMaxHechicera) {
			poderMaxHechicera = *(vecHechicera + p);	
		} 
		
		if (*(vecRival + p) > poderMaxRival) {
			poderMaxRival = *(vecRival + p);		
		}
		
	}
	
	if(cantidadH>cantidadR || cantidadH==cantidadR ) {
		printf("La hechicera gano el juego\n");
		printf("El poder promedio de los monstruos de la hechicera es: %.2f\n", promedioHechicera);
	} else if  (cantidadH<cantidadR) {
		printf("El rival gano el juego\n");
		printf("El poder promedio de los monstruos del rival es: %.2f\n", promedioRival);
	}
	
	
	if(poderMaxHechicera > poderMaxRival) {
		printf ("El poder maximo es del monstruo de la hechicera y su poder es: %d\n", poderMaxHechicera);
	} else if(poderMaxHechicera < poderMaxRival) {
		printf ("El poder maximo es del monstruo del rival y su poder es: %d\n", poderMaxRival);
	}
	
}
