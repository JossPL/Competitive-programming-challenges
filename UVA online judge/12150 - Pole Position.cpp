/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para este ejercicio por cada dato se trataba de meterlo a la posicion que en teoria le corresponde.
Si en algun momento se encuentran dos carros que llegan a la misma posicion en la pole original, entonce el tablero esta completamente descompuesto.
En otro caso, la solucion es valida y soo se imprime.

La complejidad de este algortimo es O(n) con n la cantidad de carros.
*/


#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	vector<int> cars(n+1,0), pole(n+1,0), ans(n+1,0);
	
	for(int i=1; i<=n; i++)
		cin>>cars[i]>>pole[i];
	
	for(int i=1; i<=n; i++){
		if(i+pole[i]<1 || i+pole[i]>n){
			cout<<-1<<endl;
			return;
		}
		if(ans[i+pole[i]]==0)
			ans[i+pole[i]]=cars[i];
		else{
			cout<<-1<<endl;
			return;
		}
	}
		
	for(int i=1; i<=n-1; i++){
		cout<<ans[i]<<" ";
	} cout<<ans[n]<<endl;
	
}

int main(){
	int t; cin>>t;
	while(t!=0){
		solve(t);
		cin>>t;
	}
	
	return 0;
}
