/*Funcion entregar vuelto*/

#include <stdio.h>

int main(){
	
	int valor[3]; //Valores de billetes a utilizar preestablecidos
	int billetes[3];
	int disponibilidad[3]; 
	int i = 0;
	int ingreso, apagar, vuelto, division;
	
	for(i=0; i<=3; i++)
	{
		printf("Ingrese los valores de billetes a utilizar (4 tipos):" );
		scanf("%d", &valor[i]);
	}
	
	printf("\n");
	
	for(i=0; i<=3; i++)
	{
		printf("Ingrese la disponibilidad de billetes de cada tipo:" ); //Se declara la cantidad de billetes que tiene cargados la maquina
		scanf("%d", &disponibilidad[i]);
	}
	
	
	printf("\n");
	 
	printf("Ingrese monto a pagar:");
	scanf("%d", &apagar);
	
	printf("Ingrese el monto que ingreso el usuario: ");
	scanf("%d", &ingreso);
	
	vuelto = ingreso - apagar; //Se considera que se verifico con anterioridad que el ingreso es igual o mayor que el monto a pagar.
	
	i=3; //Se reinicia la variable i, ya que cuando se hace el ingreso de los valores de cada billete, i queda cargada en 4
	
	do{
	    division = vuelto / valor[i]; //division es una variable del tipo entero, por lo cual no se guardan en ella los decimales de la division

	 	if(division != 0) //Cuando la division da mayor a cero se guarda el resultado en billetes
		{
			
			if(disponibilidad[i] >= division)
			{
				billetes[i] = division;       //Billetes indica la cantidad de billites de cada denominacion
				
				vuelto = vuelto - (division * valor[i]);    //Se modifica el monto de vuelto, para seguir dividiendo lo restante
				
				disponibilidad[i] = disponibilidad[i] - division;			
		    }
			else
			{
				if(disponibilidad != 0){
					billetes[i] = disponibilidad[i];
					vuelto = vuelto - (disponibilidad[i] * valor[i]);
				}
			}
		}
		else
		{
		    billetes[i] = 0;  //Si la division da con decimales no se requieren esa denominacion de billetes y se sigue a la siguiente
		}
		
		i--;
		
	}while(i >= 0); 
	
	
	printf("\nSe entregan: \t%d billetes de %d", billetes[0], valor[0]);
	printf(" \n\t\t%d billetes de %d", billetes[1], valor[1]);
	printf(" \n\t\t%d billetes de %d", billetes[2], valor[2]);
	printf(" \n\t\t%d billetes de %d", billetes[3], valor[3]);
	
	return 0;
}

