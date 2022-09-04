/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para resolver este problema, ademas de tener la matriz dada como input que contiene 0's y 1's se creo una matriz adicional que guarda 
la suma acumulada desde la casilla actual hasta la casilla [0][0]. 
De esta forma iteraremos sobre toda la matriz, donde el valor sobre el que estemos representara la esquina inferior derecha de una posible solucion. 
Luego, para todos los puntos que esten a la izquierda y arriba del actual calcularemos la suma de los elementos del rectangulo que se forma. 
Asi, si la suma es 0, significa que todo ese cuadro esta limpio y puede ser elegido. Iterando sobre toda la matriz podemos encontrar el maximo.

La complejidad de este algoritmo es O(n^2m^2), donde m y n son las medidas de la matriz.
*/

#include<bits/stdc++.h>

using namespace std;

int terrain[101][101];
int sum[101][101];

//	inferior derecha   superior izquierda				
int calcular_suma(int i,int j, int ii, int jj){
	return sum[i][j]-sum[i][jj-1]-sum[ii-1][j]+sum[ii-1][jj-1];
}

int main(){
	int m,n;cin>>m>>n;
	while(m!=0 && n!=0){
		//Leo la matriz
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cin>>terrain[i][j];
			}
		}
		
		// La matriz sum contiene la suma del rectangulo desde la esquina superior izquierda hasta la casilla de interés.
		for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++){
				if(i*j == 0 )
					sum[i][j]=0;
				else
					sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+terrain[i][j];
			}
		}
			
		int res=0;	
		
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				//La esquina inferior derecha es [i][j]			
				for(int ii=1;ii<=i;ii++){
					for(int jj=1;jj<=j;jj++){
						if(calcular_suma(i,j,ii,jj) == 0 ){
							int area=(i-ii+1)*(j-jj+1);
							res=max(res,area);
						}
					}
				}
			}
		}
		
		cout<<res<<endl;
		cin>>m>>n;
				
	}
	return 0;
}
