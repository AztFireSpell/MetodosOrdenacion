/*
Autor: AztFireSpell https://github.com/AztFireSpell/MetodosOrdenacion
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Variables para utilizar en los metodos de ordenacion - Arreglos
int i,x,j,k,aux;
//Creacion de los arreglos
long n,*arr,*arr1;
void copiararreglo(long arr[],long arr1[]);
void mostrararreglo(long a[]);
//Variable encargada de guardar el tiempo de ejecuci�n de los m�todos
double tiempo;
//Funciones para ejecutar los m�todos de ordenamiento
void metodoshell(long arr[]);
void metodoburbuja(long arr[]);
void metodoinsercion(long arr[]);
void metodoquick(long arr[],long primero,long ultimo);

//Creamos el apuntador para el archivo de texto
FILE *f,*arre;
int main(){
	//Creaci�n del archivo que guarda los tiempos de ejecuci�n
	f=fopen("Tiempofinal.txt","w+");
	//Se crea un archivo que guarda los datos generados aleatoriamente para el arreglo
	arre=fopen("Arreglo.txt","w+");
	printf("Bienvenido usuario\n\n");
	printf("Ingresa cuantos numeros deseas generar:");
	scanf("%d",&n);
	fprintf(f,"Total de datos:%lf\nMetodos,Tiempo",n);
	
	//Usamos malloc para la gesti�n de memoria de todos los n�meros aleatorios
	arr=malloc(n*sizeof(int));
	arr1=malloc(n*sizeof(int));
	
	//Inicializamos el generador de n�meros aleatorios
	srand(time(NULL));
	
	//Generamos a la vez n�meros aleatorios negativos y positivos
	for(i=0;i<n;i++){
		x=rand()%n;
			if(i%2==0){
				x=x*-1;
			}
		arr[i]=x;
	}
	
	//Guardamso el arreglo auxiliar que es una copia del arreglo original
	copiararreglo(arr,arr1);
	fprintf(arre,"\nMostrando el arreglo generado originalmente\n");
	mostrararreglo(arr);
	printf("Metodo Shell\n");
	metodoshell(arr1);
	fflush(stdin);
	printf("Metodo Burbuja\n");
	copiararreglo(arr,arr1);
	metodoburbuja(arr1);
	fflush(stdin);
	printf("Metodo Insercion\n");
	copiararreglo(arr,arr1);
	metodoinsercion(arr1);
	fflush(stdin);
	copiararreglo(arr,arr1);
	printf("metodo Quicksort\n");
	clock_t start = clock();
	metodoquick(arr1,0,n-1);
	printf("\nTiempo transcurrido metodo quicksort: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	tiempo=((double)clock() - start) / CLOCKS_PER_SEC;
	fprintf(f,"Quicksort,%f\n",tiempo);
	system("pause");
	fclose(f);
	fclose(arre);
	system("cls");
	printf("\tAbriendo grafica en 5 segundos...");
	printf("\n\tNOTA: SI EL DOCUMENTO NECESITA LA HABILITACION DE MACROS \n\tFAVOR DE SELECCIONAR -HABILITAR CONTENIDO-\n");
	
	for(i=0;i<37540;i++){
		for(j=0;j<32767;j++){
			
		}
	}
	
	system("graficar.bat");
	system("cls");
	return 0;
}

void copiararreglo(long arr[],long arr1[]){
	for(i=0;i<n;i++){
		arr1[i]=arr[i];
	}
}
void mostrararreglo(long arr[]){
	for(i=0;i<n;i++){
		fprintf(arre,"[%d]\t",arr[i]);
	}
}
void metodoshell(long arr[]){
	clock_t start = clock();
		for(i=n/2;i!=0;i=i/2){
		j=1;
		do {
			j=0;
			for(k=i;k<n;k++){
				if(arr[k-i]>arr[k]){
					aux=arr[k];
					arr[k]=arr[k-i];
					arr[k-i]=aux;
					j++;
				}
			}
		} while(j!=0);
	}
	printf("\nTiempo transcurrido metodo shell: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	tiempo=((double)clock() - start) / CLOCKS_PER_SEC;
	fprintf(f,"\nShell,%f\n",tiempo);
}
void metodoburbuja(long arr[]){
	clock_t start = clock();
     	int j,i,aux;
		for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]>=arr[j]){
				aux=arr[i];
				arr[i]=arr[j];
				arr[j]=aux;
			}
		}

	}
	printf("\nTiempo transcurrido metodo burbuja: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	tiempo=((double)clock() - start) / CLOCKS_PER_SEC;
	fprintf(f,"Burbuja,%f\n",tiempo);
}
void metodoinsercion(long arr[]){
        clock_t start = clock();
           int a, i, index;
                for(i=1;i<n;i++){
                index=arr[i];
	          a=i-1;
	           while(a>=0 && arr[a]>index){
	           arr[a+1]=arr[a];
	           a--;
                                    }
               arr[a+1]=index;
              }
     printf("\nTiempo transcurrido metodo insercion: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	tiempo=((double)clock() - start) / CLOCKS_PER_SEC;
	fprintf(f,"Insercion,%f\n",tiempo);
}
void metodoquick(long arr[],long primero,long ultimo){
 int i,j,central;
	double pivote;
	central=(primero+(ultimo))/2;
	pivote=arr[central];	
	i=primero;
	j=ultimo;
	do{
		while(arr[i]<pivote) i++;
		while(arr[j]>pivote) j--;
		if(i<=j){
			double tmp;
			tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
			i++;
			j--;
		}
	}while(i<=j);
	if(primero<j)
	metodoquick(arr,primero,j);
	if(i<ultimo)
	metodoquick(arr,i,ultimo);
     }
