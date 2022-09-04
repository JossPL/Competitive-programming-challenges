/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Primeramente, dado un numero y, veremos en que cuadro de los centrados en el centro del cuadrado original se encontrara la posicion deseada.
Posteriormente comenzamos en el valor obtenido con la funcion previamente mencionada a avanzar hasta encontrar la posicion deseada.
Este proceso se hace recorriendo cuador por cuadro sobre el contorno mencionado hasta llegar al resultado.

La complejidad de este algoritmo es O(tn^(1/2)), donde n es el valor dado para buscar y t la cantidad de casos. 
Esto porque el contorno sobre el que se busca n tiene de medidas n^1/2.
*/


#include <bits/stdc++.h>

using namespace std;

//Funcuion que regresa en que cuadrado estara
int bigger_odd_square(int y){
	int sq=sqrt(y);
	sq|=1; //Lo convierto en impar
	if(sq*sq < y)
		sq+=2;
	return sq;
}

int main(){
	int s,y;cin>>s>>y;
	while( s!=0 && y!=0 ){
		int k=s/2, x=bigger_odd_square(y);
		int col_res=k+1+x/2, fila_res=k+1+x/2;
		
		int fila[]={-1,0,1,0};
		int col[]={0,-1,0,1};
		int i=0;
		
		while(x*x-i!=y){
			int lado=i/(x-1);
			fila_res+=fila[lado];
			col_res+=col[lado];
			i++;
		}
		cout<<"Line = "<<fila_res<<", column = "<<col_res<<"."<<endl;
		cin>>s>>y;
	}
	return 0;
}
