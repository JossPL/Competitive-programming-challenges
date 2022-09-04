/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

La idea de solucion consiste en guardar las repeticiones de cada elemento de cada lista por separado
En un set guardamos los numeros que han aparecido

Entonces, las operaciones que debemos hacer es la suma de las diferencias positivas de las diferencias 
de las repeticiones de cada numero, pues esto nos dice si debemos insertar o remover numeros de una lista u otra

Para el paso anterior, recorremos el set de apariciones y calculamos las diferencias con el map de repeticiones

La complejidad de este algoritmo es O((n+m)log(n+m)), con n y m la cantidad de numeros en cada una de las listas,
pues por cada elemento se accede al set y al map.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
	int m, n; cin>>m>>n;
	map<int, int> a, b;
	set<int> list;
	
	//Guardamos repeticiones
	int aux;
	for(int i=0; i<m; i++){
		cin>>aux;
		a[aux]++;
		list.insert(aux);
	}
	for(int i=0; i<n; i++){
		cin>>aux;
		b[aux]++;
		list.insert(aux);
	}
	
	//Calculamos la suma de diferencias
	int ans=0;
	for(auto hold : list)
		ans+=abs(a[hold]-b[hold]);
	
	cout<<ans<<"\n";
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t; cin>>t;
	while(t--) solve();
	
	return 0;
}
