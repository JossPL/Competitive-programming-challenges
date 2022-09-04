/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para cada una de las filas del arrreglo se busco el primer elemento que sea mayor o igual a l.
Posteriormente avanzando en diagonal se ve que tan grande podemos crear el cuadrado a partir de esta casilla. 
Haciendo esto con cadauna de las filas obtenemops el resultado final.

La complejidad de este algoritmo es O(qn ( log(m)+n+m )) donde q es la cantidad de queries, n las filas y m las columnas. 
Pues por cada querie se hace un ciclo sobre todas las filas. Luego dentro de cada uno de estos se hcae una binary search y un recorrido de a lo mas min(m+n)
pasos. 
*/


#include <bits/stdc++.h>

using namespace std;

int grid[500][500];

int main(){
	int n,m;cin>>n>>m;
	while(n != 0 || m !=0){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>grid[i][j];
			}
		}
		int q;cin>>q;
		for(int k=0;k<q;k++){
			int l,u;cin>>l>>u;
			int max_size=0;
			for(int i=0;i<n;i++){
				int j=lower_bound(grid[i], grid[i]+m, l)-grid[i];
				int size=max_size;
				while(j+size<m && i+size<n && grid[i+size][j+size] <= u)
					size++;
				max_size=size;
			}
			cout<<max_size<<endl;
		}
		cout<<"-"<<endl;
		cin>>n>>m;
	}
	return 0;
}

/*
4 5
13 21 25 33 34
16 21 33 35 35
16 33 33 45 50
23 51 66 83 93
3
22 90
33 35
20 100
4 4
1 7 9 11
5 8 10 12
7 10 15 17
11 19 30 41
4
6 20
7 9
10 10
13 14
0 0

*/
