#include <stdio.h>
#include <windows.h> //Si usa linux o mac, no me acuerdo la librería :(
#define MAX 5

/* CaracolA (2.0v) */
// m es la matriz a evaluar
// f (fila) y c (columna) son los valores que recorren la matriz en caracol
// lim (limite) es el valor máximo de llegada
// min (mínimo) es el valor mínimo de llegada
// lim y min cuando llega a cierto punto, cambian para evaluar el problema mas pequeño
// es decir, lim - 1, min + 1; de tal forma que f y c fluctuen en zon a los límites
// estor funcionan como un techo y un piso.
int caracolA(int m[][MAX], int f, int c, int lim, int min);

int main(){

	int matriz[MAX][MAX] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
	
	printf("La suma es: *%i*\n", caracolA(matriz,0,0,MAX-1,0));
	
	return 0;
}

int caracolA(int m[][MAX], int f, int c, int lim, int min){
	
	int aux;
	
	Sleep(500);
	printf("\n\a[%i,%i]",f+1, c+1);

	aux = m[f][c];

	if((lim == min) || (c == min && f == lim && (lim-1) == min))
		aux += 0;
	else if(c < lim && f == min)
		aux += caracolA(m,f,c+1,lim,min);
	else if(f < lim && c == lim)
		aux += caracolA(m,f+1,c,lim,min);
	else if(c > min /*&& f == lim*/)
		aux += caracolA(m,f,c-1,lim,min);
	else if(f > (min+1) /*&& c == min*/)
		aux += caracolA(m,f-1,c,lim,min);
	else
		aux += caracolA(m,f,c+1,lim-1,min+1);
	
	return aux;
}
