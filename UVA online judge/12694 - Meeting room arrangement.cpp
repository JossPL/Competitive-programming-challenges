/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para cada hora de inicio se guardo la minima hora de final que podia tener de acuerdo con el conjunto de horarios dados. 
Posteriormente, comenzamos desde 9, vemos cual es la cantidad maxima de eventos que se pueden realizar si 9 es la hora de inicio. 
Luego, para cada uno de los numeros menores, se considera si lo mejor realizar o no el evento que comienza en esa hora. 

La complejidad de este algoritmo es O(n+h) donde n es la cantidad de eventos candidatos a aoparecer. Esta se alcanza a la hora de leer los datos. 
Posteriormente apra calcular la solucion se hacen h ciclos, donde h es la cantidad de hors que el salon estara abierto. 
*/


#include <bits/stdc++.h>

using namespace std;

void solve(){
	map<int,int> final;
	int a,b; cin>>a>>b;
	while(a!=0 || b!=0){
		if(final[a] == 0)
			final[a]=b;
		else
			final[a]=min(final[a],b);
		cin>>a>>b;
	}
	
	vector<int> sol(11,0);
	
	for(int i=9;i>=0;i--){
		if(final[i]==0)
			sol[i]=sol[i+1];
		else{
			sol[i]=max(sol[final[i]]+1,sol[i+1]);
		}
	}
	
	cout<<sol[0]<<endl;
}


int main(){
	int n;cin>>n;
	while(n--)
		solve();
	return 0;
}
